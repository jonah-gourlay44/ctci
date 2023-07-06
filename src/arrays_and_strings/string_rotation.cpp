#include "arrays_and_strings/arrays_and_strings.h"
#include <stdio.h>
#include <string.h>

namespace arrays_and_strings
{

/**
 * @brief Function to check if one string is a substring of another
 * @param s1 The string to search in
 * @param s2 The substring to search for
 */
bool isSubstring(const std::string& s1, const std::string& s2)
{
    return s1.find(s2) != std::string::npos;
}

bool stringRotation(const std::string& s1, const std::string& s2)
{
    if (s1.size() != s2.size()) {
        return false;
    }

    std::string concat;
    concat.resize(s2.size() * 2);

    memcpy(&concat[0], &s2[0], sizeof(s2[0]) * s2.size());
    memcpy(&concat[s2.size()], &s2[0], sizeof(s2[0]) * s2.size());

    if (isSubstring(concat, s1)) {
        return true;
    }

    return false;
}

} // namespace arrays_and_strings