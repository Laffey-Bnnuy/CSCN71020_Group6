#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../PolygonChecker/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleSolverTests
{
	TEST_CLASS(TriangleSolverTests)
	{
	public:
		
		TEST_METHOD(TestNotATriangle)
        {
            // Test case where sides do not form a triangle
            Assert::AreEqual("Not a triangle", analyzeTriangle(1, 2, 3));
            Assert::AreEqual("Not a triangle", analyzeTriangle(5, 1, 1));
        }

        TEST_METHOD(TestEquilateralTriangle)
        {
            // Test case for equilateral triangle
            Assert::AreEqual("Equilateral triangle", analyzeTriangle(3, 3, 3));
            Assert::AreEqual("Equilateral triangle", analyzeTriangle(5, 5, 5));
        }

        TEST_METHOD(TestIsoscelesTriangle)
        {
            // Test case for isosceles triangle
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(3, 3, 2));
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(4, 4, 6));
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            // Test case for scalene triangle
            Assert::AreEqual("Scalene triangle", analyzeTriangle(3, 4, 5));
            Assert::AreEqual("Scalene triangle", analyzeTriangle(7, 10, 5));
        }

        TEST_METHOD(TestAnalyzeTriangle_BoundaryCases)
        {
            Assert::AreEqual("Not a triangle", analyzeTriangle(1, 1, 2)); // Degenerate case
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(2, 2, 3)); // Near-degenerate valid triangle
            Assert::AreEqual("Scalene triangle", analyzeTriangle(3, 4, 6)); // Non-degenerate valid triangle
        }



        // Tests for angle solver
        TEST_METHOD(TestAngleSolver_ValidAngle)
        {
            // Test case for valid angle calculation
            float angle = AngleSolver(3, 4, 5);
            Assert::IsTrue(abs(angle - 90.0) < 0.01); // Check if angle is approximately 90 degrees
        }

        TEST_METHOD(TestAngleSolver_ZeroAngle)
        {
            // Test case for invalid angle calculation (degenerate case)
            float angle = AngleSolver(1, 1, 2);
            Assert::IsTrue(abs(angle - 0.0) < 0.01); // Should result in approximately 0 degrees
        }
        TEST_METHOD(TestAngleSolver_RightTriangle)
        {
            float angle = AngleSolver(3, 4, 5);
            Assert::IsTrue(abs(angle - 90.0) < 0.01); // Approximately 90 degrees
        }

        TEST_METHOD(TestAngleSolver_AcuteTriangle)
        {
            float angle = AngleSolver(7, 8, 9);
            Assert::IsTrue(angle > 0.0 && angle < 90.0); // Acute angle
        }

        TEST_METHOD(TestAngleSolver_ObtuseTriangle)
        {
            float angle = AngleSolver(8, 6, 10);
            Assert::IsTrue(angle > 90.0 && angle < 180.0); // Obtuse angle
        }

        TEST_METHOD(TestAngleSolver_BoundaryCases)
        {
            Assert::IsTrue(abs(AngleSolver(1, 1, 1) - 60.0) < 0.01); // Equilateral triangle, each angle ~60 degrees
            Assert::IsTrue(abs(AngleSolver(5, 5, 8) - 53.13) < 0.01); // Isosceles triangle, angle approximation
        }

        TEST_METHOD(TestAngleSolver_InvalidInputs)
        {
            Assert::IsTrue(abs(AngleSolver(1, 1, 2) - 0.0) < 0.01); // Degenerate case
            Assert::IsTrue(abs(AngleSolver(0, 0, 0) - 0.0) < 0.01); // Zero-length sides
            Assert::IsTrue(abs(AngleSolver(-1, -1, -1) - 0.0) < 0.01); // Negative sides
        }

        TEST_METHOD(TestAngleSolver_LargeTriangles)
        {
            Assert::IsTrue(abs(AngleSolver(300, 400, 500) - 90.0) < 0.01); // Right triangle with large sides
            Assert::IsTrue(abs(AngleSolver(1000, 1200, 1300) - 58.22) < 0.01); // General large triangle
        }

    };
}
