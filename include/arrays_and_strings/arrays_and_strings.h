#pragma once

#include <string>

/**
 * @brief An algorithm to determine if a string has all unique characters
 * @param str The input string
 * @param method The solution method to use: "standard", "in_place", or "in_place_sort"
 * @return true If the string is unique and false otherwise
 */
bool isUnique(const std::string& str, const std::string& method = "standard");

/**
 * @brief Given two strings, this method determines if one is a permutation of the other
 * @param str1 The first string
 * @param str2 The second string
 * @return true If str1 is a permutation of str2 and false otherwise
 */
bool checkPermutation(const std::string& str1, const std::string& str2);

/**
 * @brief A method to replace all space in a string with '%20'
 * @param str A string represented as a character array
 * @param length The true length of the string
 * @details Enough room must be provided at the end of str to contain additional characters
 */
void URLify(char* str, int length);

/**
 * @brief A function to check if a string is a permutation of a palindrome
 * @param str The string to check
 * @return true If str is a permutation of a palindrome and false otherwise
 */
bool palindromePermutation(const std::string& str);

/**
 * @brief A function to check if two strings are one edit away from one another
 * @param str1 The original string
 * @param str2 The string after editing
 * @return true If str1 is less than or equal to one edit away from str2
 * @details Possible edits are: inserting a character, removing a character, or replacing a character
 */
bool oneAway(const std::string& str1, const std::string& str2);

/**
 * @brief A method to perform basic string compression using the counts of repeated characters
 * @param str The uncompressed string
 * @return std::string The compressed version of str
 * @details Returns the original string if the compressed version is not smaller
 */
std::string stringCompression(const std::string& str);

/**
 * @brief A method to rotate an NxN matrix by 90 degrees'
 * @param mat The matrix to rotate
 * @param N The matrix side-length
 */
void rotateMatrix(uint32_t** mat, size_t N);

/**
 * @brief A method to set the row and column of any zero element in a MxN matrix to zero
 * @param mat The matrix to zero
 * @param M The number of matrix rows
 * @param N The number of matrix columns
 */
void zeroMatrix(uint32_t** mat, size_t M, size_t N);

/**
 * @brief A method to determine if one string is a rotation of another
 * @param s1 The original string
 * @param s2 The potentially rotated string
 * @return true If s2 is a rotation of s1
 */
bool stringRotation(const std::string& s1, const std::string& s2);