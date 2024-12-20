#include "pch.h"
#include "CppUnitTest.h"

//minh duc nguyen 9002756 - testing for rectangle feature 
extern "C" {
#include "../PolygonChecker/RectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTestForRectangleSolver)
    {
    public:
        // test cases for swap function 
        TEST_METHOD(ArraySwapFirstAndLastValue)
        {
            POINT points[ARRAY_LENGTH] = { {2, 2}, {8, 8}, {9, 9}, {15, 15} };
            POINT expected[ARRAY_LENGTH] = { {15, 15}, {8, 8}, {9, 9}, {2, 2} };

            ArraySwap(0, 3, points);

            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }

        TEST_METHOD(ArraySwapNegativeValues)
        {
            POINT points[ARRAY_LENGTH] = { {-6, -6}, {-7, -7}, {10, 10}, {-16, -16} };
            POINT expected[ARRAY_LENGTH] = { {-6, -6}, {10, 10}, {-7, -7}, {-16, -16} };

            ArraySwap(1, 2, points);

            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }

        TEST_METHOD(ArraySwapSameValues)
        {
            POINT points[ARRAY_LENGTH] = { {5, 5}, {8, 8}, {10, 10}, {14, 14} };
            POINT expected[ARRAY_LENGTH] = { {5, 5}, {8, 8}, {10, 10}, {14, 14} };

            ArraySwap(2, 2, points);

            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }

        // test case for sorting function 
        TEST_METHOD(SortingSortedArray)
        {
            POINT points[ARRAY_LENGTH] = { {5, 5}, {8, 8}, {10, 10}, {14, 14} };
            POINT expected[ARRAY_LENGTH] = { {5, 5}, {8, 8}, {10, 10}, {14, 14} };

            Sorting(points);

            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }

        TEST_METHOD(SortingNotSortedArray)
        {
            POINT points[ARRAY_LENGTH] = { {10, 10}, {5, 5}, {14, 14}, {8, 8} };
            POINT expected[ARRAY_LENGTH] = { {5, 5}, {8, 8}, {10, 10}, {14, 14} };

            Sorting(points);

            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }

        TEST_METHOD(SortingArrayWithNegativeValues)
        {
            POINT points[ARRAY_LENGTH] = { {-19, -6.5}, {-15, -8.1}, {-12.7, -10}, {-5.8, -7.4} };
            POINT expected[ARRAY_LENGTH] = { {-19, -6.5}, {-15, -8.1}, {-12.7, -10}, {-5.8, -7.4} };

            Sorting(points);


            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                Assert::AreEqual(expected[i].x, points[i].x);
                Assert::AreEqual(expected[i].y, points[i].y);
            }
        }
        // test case for area calculate area calculate function 
        TEST_METHOD(AreaCalculatePositiveValues)
        {
            float length[SIDE_LENGTH] = { 5.6f, 7.8f, 0.0f, 0.0f };
            float expectedArea = 43.68f;

            float actualArea = AreaCalculate(length);

            Assert::AreEqual(expectedArea, actualArea, 0.01f, L"area calculation failed for positive values.");
        }

        TEST_METHOD(AreaCalculateZeroValues)
        {
            float length[SIDE_LENGTH] = { 0.0f, 7.6f, 0.0f, 0.0f };
            float expectedArea = 0.0f;

            float actualArea = AreaCalculate(length);

            Assert::AreEqual(expectedArea, actualArea, 0.01f, L"area calculation failed for zero values.");
        }

        TEST_METHOD(AreaCalculateNegativeValues)
        {
            float length[SIDE_LENGTH] = { -6.0f, 17.4f, 0.0f, 0.0f };
            float expectedArea = -104.4f;

            float actualArea = AreaCalculate(length);

            Assert::AreEqual(expectedArea, actualArea, 0.01f, L"area calculation failed for negative values.");
        }
        // test cases for perimeter calculate function
        TEST_METHOD(PerimeterCalculatePositiveValues)
        {
            float length[SIDE_LENGTH] = { 1.0f, 10.0f, 3.5f, 6.5f };
            float expectedPerimeter = 21.0f;

            float actualPerimeter = PerimeterCalculate(length);

            Assert::AreEqual(expectedPerimeter, actualPerimeter, 0.01f, L"Perimeter calculation failed for positive values.");
        }

        TEST_METHOD(PerimeterCalculateZeroValues)
        {
            float length[SIDE_LENGTH] = { 0.0f, 0.0f, 0.0f, 0.0f };
            float expectedPerimeter = 0.0f;

            float actualPerimeter = PerimeterCalculate(length);

            Assert::AreEqual(expectedPerimeter, actualPerimeter, 0.01f, L"Perimeter calculation failed for zero values.");
        }

        TEST_METHOD(PerimeterCalculateNegativeValues)
        {
            float length[SIDE_LENGTH] = { -1.0f, -10.0f, -3.5f, -6.5f };
            float expectedPerimeter = -21.0f;

            float actualPerimeter = PerimeterCalculate(length);

            Assert::AreEqual(expectedPerimeter, actualPerimeter, 0.01f, L"Perimeter calculation failed for negative values.");
        }
        TEST_METHOD(CalculateRectangleNonRectangle)
        {
            // Arrange
            POINT points[ARRAY_LENGTH] = {
                {0.0f, 0.0f}, // Point 1
                {4.0f, 0.0f}, // Point 2
                {2.0f, 3.0f}, // Point 3
                {0.0f, 3.0f}  // Point 4
            };
            float length[SIDE_LENGTH] = { 0.0f };

            // Act
            bool isRectangle = CalculateRectangle(points, length);

            // Assert
            Assert::IsFalse(isRectangle, L"Incorrectly identified a non-rectangle as a rectangle.");
        }

        TEST_METHOD(CalculateRectangleNegativeCase)
        {
            // Arrange
            POINT points[ARRAY_LENGTH] = {
                {0.0f, 0.0f}, // Point 1
                {2.0f, 0.0f}, // Point 2
                {3.0f, 1.0f}, // Point 3 (not forming a rectangle)
                {0.0f, 3.0f}  // Point 4
            };
            float length[SIDE_LENGTH] = { 0.0f };

            // Act
            bool isRectangle = CalculateRectangle(points, length);

            // Assert
            Assert::IsFalse(isRectangle, L"Rectangle identification passed for an invalid rectangle.");
        }
    };
}