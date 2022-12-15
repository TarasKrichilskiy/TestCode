#ifndef SUDOKU_OFFSPRING_H
#define SUDOKU_OFFSPRING_H

#include "Sudoku.h"
#include "Offspring.h"
#include "Puzzle.h"

using namespace std;

class SudokuOffspring : public Offspring {
public:
    /**
     *
     */
    SudokuOffspring() = default;

    /**
     *
     * @param puzzle
     * @return
     */
    Sudoku* makeOffspring(Sudoku* puzzle);
};

#endif //SUDOKU_OFFSPRING_H
