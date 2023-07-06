#include "arrays_and_strings/arrays_and_strings.h"

#include <list>

namespace arrays_and_strings
{

// Approach 1: Iterate through string and append character with count
// to new string

std::string stringCompression_1(const std::string& str)
{
    if (str.size() == 0) {
        return str;
    } 

    char prev_char = str[0];
    int count = 0;
    std::string new_str;
    for (int idx = 0; idx < str.size(); idx++) {
        if (str[idx] != prev_char) {
            new_str += prev_char + std::to_string(count);
            count = 1;
            prev_char = str[idx];
        } else {
            count++;
        }
    }
    new_str += prev_char + std::to_string(count);


    if (new_str.size() >= str.size()) {
        return str;
    }

    return new_str;
}

// Approach 2: Precompute necessary length

std::string stringCompression(const std::string& str)
{
    if (str.size() == 0) {
        return str;
    }

    std::list<std::pair<char, int>> counts;
    int count = 0;
    char prev_char = str[0];
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != prev_char) {
            counts.push_front(std::make_pair(prev_char, count));
            prev_char = str[i];
            count = 1;
        } else {
            count++;
        }
    }
    counts.push_front(std::make_pair(prev_char, count));

    if (counts.size() == str.size()) {
        return str;
    }

    std::string new_str;
    new_str.resize(counts.size() * 2);
    int idx = 0;
    while (counts.size() > 0) {
        auto count_pair = std::move(counts.back());
        counts.pop_back();

        new_str[idx++] = count_pair.first;
        new_str[idx++] = *std::to_string(count_pair.second).c_str();
    }

    return new_str;
}

} // namespace arrays_and_strings