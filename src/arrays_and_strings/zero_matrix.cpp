#include "arrays_and_strings/arrays_and_strings.h"
#include <unordered_set>

void zeroMatrix(uint32_t** mat, size_t M, size_t N)
{
    // Place zero rows and cols into hash sets
    bool first_row = false;
    bool first_col = false;
    for (size_t row = 0; row < M; row++) {
        for (size_t col = 0; col < N; col++) {
            if (mat[row][col] == 0) {
                if (row == 0) {
                    first_row = true;
                }
                if (col == 0) {
                    first_col = true;
                }

                mat[0][col] = 0;
                mat[row][0] = 0;
            }
        }
    }

    // Zero columns
    for (size_t col = 1; col < N; col++) {
        if (mat[0][col] == 0) {
            for (size_t row = 0; row < M; row++) {
                mat[row][col] = 0;
            }
        }
    }

    // Zero rows
    for (size_t row = 1; row < M; row++) {
        if (mat[row][0] == 0) {
            for (auto col = 0; col < N; col++) {
                mat[row][col] = 0;
            }
        }
    }

    // Zero first col after col vals have been read
    if (first_col) {
        for (auto row = 0; row < M; row++) {
            mat[row][0] = 0;
        }
    }
    
    // Zero first row after row vals have been read
    if (first_row) {
        for (auto col = 0; col < N; col++) {
            mat[0][col] = 0;
        }
    }
}