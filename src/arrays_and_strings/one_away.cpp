#include "arrays_and_strings/arrays_and_strings.h"

namespace arrays_and_strings
{

bool oneAway(const std::string& str1, const std::string& str2)
{
    // No edit case
    if (str1 == str2) {
        return true;
    }

    int str1_sz = str1.size();
    int str2_sz = str2.size();

    // Multiple additions or multiple removals
    int size_difference = str1_sz - str2_sz;
    int edits = 0;
    if (abs(size_difference) > 1) {
        return false;
    } else if (size_difference == -1) { // str1 is smaller than str2
        int i = 0;
        int j = 0;
        while (j < str1_sz && i < str2_sz) {
            if (j == str2_sz - 2 && edits == 0) { // Character added at the end
                return true;
            } else if (str1[j] != str2[i]) {
                i++;
                edits++;
            } else {
                j++;
                i++;
            }
        }
    } else if (size_difference == 1) { // str1 is larger than str2
        int i = 0;
        int j = 0;
        while (j < str2_sz && i < str1_sz) {
            if (j == str1_sz - 2 && edits == 0) { // Character removed from the end
                return true;
            } else if (str2[j] != str1[i]) {
                i++;
                edits++;
            } else {
                j++;
                i++;
            }
        }
    } else { // str1 and str2 are the same size
        for (int i = 0; i < str1_sz; i++) {
            if (str1[i] != str2[i]) {
                edits++;
            }
        }
    }

    return edits <= 1;
}

} // namespace arrays_and_strings