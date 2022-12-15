

#ifndef OFFSPRING_H
#define OFFSPRING_H

#include "Puzzle.h"
#include "Sudoku.h"

/**
 * Offspring is used by PuzzleFactory to create new Puzzles from old ones.
 */
class Offspring {
public:
    /**
     * constructor
     */
    explicit Offspring() = default;

    /**
     * @param puzzle a source puzzle
     * @return an output offspring puzzle mutated from the input
     */
    virtual Sudoku* makeOffspring(Sudoku* puzzle){
        return nullptr;
    };
};


#endif //OFFSPRING_H
