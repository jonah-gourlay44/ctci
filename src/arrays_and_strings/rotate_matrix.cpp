#include "arrays_and_strings/arrays_and_strings.h"

void rotateMatrix(uint32_t** mat, size_t N)
{
    // Compute matrix transpose in-place
    for (int row = 0; row < N; row++) {
        for (int col = row; col < N; col++) {
            if (row == col) // don't need to swap
                continue;

            std::swap(mat[row][col], mat[col][row]);
        }
    }

    // Compute matrix reflection about vertical axis of symmetry
    int col_l = 0;
    int col_r = N-1;
    while (col_l < col_r) {
        for (int row = 0; row < N; row++) {
            std::swap(mat[row][col_l], mat[row][col_r]);
        }
        col_l++;
        col_r--;
    }
}