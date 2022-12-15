//
// Created by Olive on 8/3/2022.
//

#ifndef PUZZLE_FACTORY_H
#define PUZZLE_FACTORY_H

#include "Puzzle.h"
#include "Offspring.h"
#include "SudokuOffspring.h"
#include "Sudoku.h"

using namespace std;

/**
 * PuzzleFactory is a class that has the pattern for producing puzzles.
 * The PuzzleFactory takes a puzzles and give a new puzzle that has new random numbers
 */
class PuzzleFactory {
public:

    /**
     * destructor
     */
    ~PuzzleFactory() {
        delete offspring;
    }

    /**
     * create a puzzle
     * @param p a source puzzle to base the new one off of
     * @return a Sudoku* with similar but randomized traits
     */
    virtual Sudoku* createPuzzle(Sudoku* p);

    Offspring* offspring = new SudokuOffspring(); // an offspring for creating new sudokus

};

#endif //PUZZLE_FACTORY_H
