#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <ctime>
#include "../AP_Lab№6.4.рек/AP_Lab№6.4.рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestFindMaxIndex)
        {
            int arr[] = { 1, 5, 3, 9, 2 };
            int result = findMaxIndex(arr, 5);
            Assert::AreEqual(3, result);
        }

        TEST_METHOD(TestProductBetweenZeros)
        {
            int arr[] = { 1, 0, 2, 2, 3, 0, 4 };
            int result = productBetweenZeros(arr, 7);
            Assert::AreEqual(12, result);
        }
        TEST_METHOD(TestGenerateArray)
        {
            srand((unsigned)time(NULL));
            int arr[10];
            generateArray(arr, 10);
            for (int i = 0; i < 10; i++) {
                Assert::IsTrue(arr[i] >= -10 && arr[i] <= 35);
            }
        }
    };
}