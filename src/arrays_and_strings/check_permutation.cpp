#include "arrays_and_strings.h"

bool checkPermutation(const std::string& str1, const std::string& str2)
{
    if (str1.length() != str2.length())
        return false;

    int counts[128] = { 0 };

    int len = str1.length();

    // Increment count for each character of the first word
    for (int i = 0; i < len; i++)
    {
        counts[str1[i]]++;
    }

    // Decrement count for each character of the second word
    for (int i = 0; i < len; i++)
    {
        counts[str2[i]]--;
        if (counts[str2[i]] < 0)
            return false;
    }

    return true;
}