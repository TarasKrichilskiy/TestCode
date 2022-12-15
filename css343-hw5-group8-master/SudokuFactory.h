#ifndef SUDOKU_FACTORY_H
#define SUDOKU_FACTORY_H

#include "Sudoku.h"
#include "PuzzleFactory.h"
#include "SudokuOffspring.h"

class SudokuFactory : public PuzzleFactory {

public:
    /**
     * default constructor
     */
    SudokuFactory() {};

    /**
     * create a puzzle
     * @param p a source puzzle to base off of
     * @return a Sudoku* with similar but randomized traits
     */
    Sudoku* createPuzzle(Sudoku* p);

};

#endif //SUDOKU_FACTORY_H
