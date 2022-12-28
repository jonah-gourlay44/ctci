#include <gtest/gtest.h>
#include "utils.h"

TEST(TestUtils, merge)
{
    std::vector<int> arr;

    // 0,4,6,1,2,5
    arr = { 0, 4, 6, 1, 2, 5 };

    merge(&arr[0], 0, (0 + 5) / 2, 5);

    ASSERT_EQ(arr, std::vector<int>({ 0, 1, 2, 4, 5, 6})); 

    // 0,1
    arr = {0, 1};

    merge(&arr[0], 0, (0 + 1) / 2, 1);

    ASSERT_EQ(arr, std::vector<int>({0, 1}));

    // 0,0
    arr = {0, 0};

    merge(&arr[0], 0, (0 + 1) / 2, 1);

    ASSERT_EQ(arr, std::vector<int>({0, 0}));
}

TEST(TestUtils, mergeSort)
{
    std::vector<int> arr;

    // 3,2,7,1,5,9,6
    arr = { 3, 2, 7, 1, 5, 9, 6 };

    mergeSort(arr);

    ASSERT_EQ(arr, std::vector<int>({ 1, 2, 3, 5, 6, 7, 9 }));

    // 1,1,1,1
    arr = { 1, 1, 1, 1 };

    mergeSort(arr);

    ASSERT_EQ(arr, std::vector<int>({ 1, 1, 1, 1}));

    // 0,2,1,2,1,1,3,4,2
    arr = { 0, 2, 1, 2, 1, 1, 3, 4, 2 };

    mergeSort(arr);

    ASSERT_EQ(arr, std::vector<int>({ 0, 1, 1, 1, 2, 2, 2, 3, 4 }));
}

TEST(TestUtils, getPivot)
{
    std::vector<int> arr;

    // 13,9,8,4,2,5,1
    arr = { 13, 9, 8, 4, 2, 5, 1 };

    ASSERT_EQ(getPivot(&arr[0], 0, 6), 4);
}

TEST(TestUtils, partition)
{
    std::vector<int> arr;
    int lo, hi;

    // 2,2,2,3,10,6,6,6,6
    arr = { 2, 2, 2, 3, 10, 6, 6, 6, 6 };
    
    partition(&arr[0], 0, 8, lo, hi, 6);

    ASSERT_EQ(arr, std::vector<int>({ 2, 2, 2, 3, 6, 6, 6, 6, 10 }));
    ASSERT_EQ(lo, 4);
    ASSERT_EQ(hi, 7);

    // 10,2,4,1,5,2,5,3,3,6
    arr = { 10, 2, 4, 1, 5, 2, 5, 3, 3, 6 };

    partition(&arr[0], 0, 9, lo, hi, 5);

    ASSERT_EQ(arr, std::vector<int>({ 3, 2, 4, 1, 3, 2, 5, 5, 6, 10 }));
    ASSERT_EQ(lo, 6);
    ASSERT_EQ(hi, 7);
}

TEST(TestUtils, quickSort)
{
    std::vector<int> arr;

    // 10,2,4,1,5,2,5,3,3,6
    arr = { 10, 2, 4, 1, 5, 2, 5, 3, 3, 6 };

    quickSort(arr);

    ASSERT_EQ(arr, std::vector<int>({ 1, 2, 2, 3, 3, 4, 5, 5, 6, 10 }));

    // 3,3,3,1,2,4,5,3,1
    arr = { 3, 3, 3, 1, 2, 4, 5, 3, 1 };

    quickSort(arr);

    ASSERT_EQ(arr, std::vector<int>({ 1, 1, 2, 3, 3, 3, 3, 4, 5 }));
}