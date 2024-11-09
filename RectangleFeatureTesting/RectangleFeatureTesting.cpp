#include "pch.h"
#include "CppUnitTest.h"

//minh duc nguyen 9002756 - testing for rectangle feature 
extern "C" {
#include "RectangleSolver.h" 
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
    };
}