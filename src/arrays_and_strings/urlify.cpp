#include "arrays_and_strings/arrays_and_strings.h"

#include <queue>

namespace arrays_and_strings
{

// O(n) memory requirement using queue buffer
// O(n) runtime
// n is length of the string including extra characters
void URLify1(char* str, int length)
{
    std::queue<char> buffer;
    char next_char;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            buffer.push('%');
            buffer.push('2');
            buffer.push('0');
        } else {
            buffer.push(str[i]);
        }
    }

    int i = 0;
    while(buffer.size() > 0) {
        str[i++] = buffer.front();
        buffer.pop();
    }
}

// O(1) memory requirement using swaps
// Complex runtime > O(n)
void URLify2(char* str, int length)
{
    int l = 0; // left swap pos
    int r = 0; // right swap pos
    int scan_idx = 0; // scanning position

    // Scan the entire string
    while (scan_idx < length) {
        // Check if current character is a space
        if (str[scan_idx] == ' ') {
            r = length;
            l = scan_idx + 1;
            while (l < r) {
                // Swap two characters per loop
                // We can only guarantee two extra spaces at the end of the string
                std::swap(str[l], str[r]);
                l++;
                r++;
                std::swap(str[l], str[r]);
                l++;
                r--; // reset right
            }
            // Replace spaces with URL symbols
            str[scan_idx++] = '%';
            str[scan_idx++] = '2';
            str[scan_idx] = '0';
            length += 2; // add new characters to length
        }
        scan_idx++;
    }
}


// O(1) memory requirement using two scans
// O(n) runtime
// n is length of string including extra characters
void URLify(char* str, int length)
{
    int num_spaces = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            num_spaces += 1;
        }
    }

    int URLlength = length + 2 * num_spaces;
    int i = URLlength - 1;
    for (int j = length - 1; j >= 0; j--) {
        if (str[j] == ' ') {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        } else {
            str[i--] = str[j];
        }
    }
}

} // namespace arrays_and_strings