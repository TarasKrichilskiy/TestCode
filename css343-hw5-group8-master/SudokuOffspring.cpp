#include "Sudoku.h"
#include "SudokuOffspring.h"
#include <random>

using namespace std;

/**
* @param Sudoku the parent puzzle
* @return a Sudoku with similar but randomized traits
*/
Sudoku* SudokuOffspring::makeOffspring(Sudoku* puzzle) {

    const int prob = 5; //probability
    // random generator
    mt19937 rg(random_device{}());
    // generate 0-99
    uniform_int_distribution<int> dice_100(0, 99);
    //  generate 1-9
    uniform_int_distribution<int> dice_10(1, 9);

    Sudoku* newSudoku = new Sudoku();
    //got to all Sudoku squares
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int currV = puzzle->value(i, j);
            bool currD = puzzle->determinent(i, j);

            // creat a new number if not determine and  5% prob to regenerate
            if (currV == 0 || (dice_100(rg) < prob && !currD)) {
                currV = dice_10(rg);
            }
            newSudoku->setValue(i, j, currV, currD);
        }
    }

    return newSudoku;
}
