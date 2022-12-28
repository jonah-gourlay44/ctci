#include "arrays_and_strings.h"
#include <vector>

// Approach 1: Use characters as index in boolean vector, values indicate if the char appears an odd number of times.
// If more than one char has an odd count, the string is not a palindrome permutation.

bool palindromePermutation_mysoln(const std::string& str)
{
    std::vector<bool> character_odd(256,false);
    int odds = 0;
    for (auto character: str) {
        if (character == ' ') {
            continue;
        }

        character_odd[character] = !character_odd[character];
        if (character_odd[character]) {
            odds++;
        } else {
            odds--;
        }
    }

    return odds <= 1;
}

// Solution: Use bit vector to store values

bool palindromePermutation(const std::string& str)
{
    int arr = 0;
    int idx;
    int mask;
    for (auto character : str) {
        idx = (int)character;
        mask = 1 << idx;
        if (mask == 1)
            continue;

        if ((arr & mask) == 0) {
            arr |= mask;
        } else {
            arr &= ~mask;
        }
    }

    return arr == 0 || (arr & (arr - 1)) == 0;
}