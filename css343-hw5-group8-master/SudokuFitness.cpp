#include "Sudoku.h"
#include "SudokuFitness.h"

int SudokuFitness::howFit(Sudoku& p) {
    int total = 0; // conflict number

    // check row
    for (int i = 0; i < 9; ++i) {
        int conflicts[10] = {0};
        for (int j = 0; j < 9; ++j) {
            conflicts[p.value(i, j)]++;
        }
        total = helper(conflicts, total);
    }

    // check column
    for (int i = 0; i < 9; ++i) {
        int conflicts[10] = {0};

        for (int j = 0; j < 9; ++j) {
            conflicts[p.value(j, i)]++;
        }
        total = helper(conflicts, total);
    }

    // check block
    for (int k = 0; k < 9; ++k) {
        int conflicts[10] = {0};
        int x = (k / 3) * 3;
        int y = (k % 3) * 3;
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                conflicts[p.value(i, j)]++;
            }
        }
        total = helper(conflicts, total);
    }

    return total;
}

int SudokuFitness::helper(int conflicts[], int total) {
    for (int i = 0; i < 10; ++i) {
        if (conflicts[i] > 1) {
            total += conflicts[i];
        }
    }
    return total;
}
