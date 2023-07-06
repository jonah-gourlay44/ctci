#include <gtest/gtest.h>
#include "arrays_and_strings/arrays_and_strings.h"

using namespace arrays_and_strings;

TEST(ArraysAndStrings, is_unique)
{
    EXPECT_TRUE(isUnique("wisdom"));

    EXPECT_FALSE(isUnique("hello"));

    EXPECT_FALSE(isUnique("generous"));
}

TEST(ArraysAndStrings, is_unique_in_place)
{
    EXPECT_TRUE(isUnique("wisdom", "in_place"));

    EXPECT_FALSE(isUnique("hello", "in_place"));

    EXPECT_FALSE(isUnique("generous", "in_place"));
}

TEST(ArraysAndStrings, is_unique_in_place_sort)
{
    EXPECT_TRUE(isUnique("wisdom", "in_place_sort"));

    EXPECT_FALSE(isUnique("hello", "in_place_sort"));

    EXPECT_FALSE(isUnique("generous", "in_place_sort"));
}

TEST(ArraysAndStrings, check_permutation)
{
    EXPECT_TRUE(checkPermutation("animal", "ilnmaa"));

    EXPECT_FALSE(checkPermutation("interest", "tnieseet"));
}

TEST(ArraysAndStrings, urlify)
{
    std::string test_str = "Mr John Smith    ";
    URLify(&test_str[0], 13);

    EXPECT_EQ(test_str, "Mr%20John%20Smith");

    test_str = "         ";
    URLify(&test_str[0], 3);

    EXPECT_EQ(test_str, "%20%20%20");

    test_str = " l  ";
    URLify(&test_str[0], 2);

    EXPECT_EQ(test_str, "%20l");
}

TEST(ArraysAndStrings, palindrome_permutation)
{
    EXPECT_TRUE(palindromePermutation("Tact Coa"));
    EXPECT_TRUE(palindromePermutation("atco cta"));
    EXPECT_FALSE(palindromePermutation("tt yrrf"));
    EXPECT_TRUE(palindromePermutation("r    a    c   e   c     a  r"));
}

TEST(ArraysAndStrings, one_away)
{
    EXPECT_TRUE(oneAway("pale", "ple"));
    EXPECT_TRUE(oneAway("pales", "pale"));
    EXPECT_TRUE(oneAway("pale", "bale"));
    EXPECT_FALSE(oneAway("pale", "bake"));
    EXPECT_FALSE(oneAway("ppalee", "pale"));
    EXPECT_FALSE(oneAway("pale", "hame"));
}

TEST(ArraysAndStrings, string_compression)
{
    EXPECT_EQ(stringCompression("aabcccccaaa"), "a2b1c5a3");
    EXPECT_EQ(stringCompression("abcdef"), "abcdef");
}

TEST(ArraysAndStrings, rotate_matrix)
{
    size_t sz = 4;

    uint32_t arr[sz][sz] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    
    uint32_t* b[sz];
    for (size_t i = 0; i < sz; i++) {
        b[i] = arr[i];
    }

    rotateMatrix(b, sz);

    using uvec = std::vector<uint32_t>;
    std::vector<uvec> test_mat;
    for (int i = 0; i < sz; i++) {
        test_mat.emplace_back(b[i], b[i] + sz);
    }

    EXPECT_EQ(test_mat[0], uvec({13,9,5,1}));
    EXPECT_EQ(test_mat[1], uvec({14,10,6,2}));
    EXPECT_EQ(test_mat[2], uvec({15,11,7,3}));
    EXPECT_EQ(test_mat[3], uvec({16,12,8,4}));
}

TEST(ArraysAndStrings, zero_matrix)
{
    size_t sz_x = 4;
    size_t sz_y = 5;

    uint32_t arr[sz_y][sz_x] = {
        {1, 2, 3, 4},
        {5, 0, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 0},
        {0, 18, 19, 20}
    };

    uint32_t *b[sz_y];
    for (size_t i = 0; i < sz_y; i++) {
        b[i] = arr[i];
    }

    zeroMatrix(b, sz_y, sz_x);

    using uvec = std::vector<uint32_t>;
    std::vector<uvec> test_mat;
    for (int i = 0; i < sz_y; i++) {
        test_mat.emplace_back(b[i], b[i] + sz_x);
    }

    EXPECT_EQ(test_mat[0], uvec({0,0,3,0}));
    EXPECT_EQ(test_mat[1], uvec({0,0,0,0}));
    EXPECT_EQ(test_mat[2], uvec({0,0,11,0}));
    EXPECT_EQ(test_mat[3], uvec({0,0,0,0}));
    EXPECT_EQ(test_mat[4], uvec({0,0,0,0}));
}

TEST(ArraysAndStrings, string_rotation)
{
    EXPECT_TRUE(stringRotation("yesterday", "erdayyest"));
}