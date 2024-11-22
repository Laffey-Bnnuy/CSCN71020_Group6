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
    };
}
