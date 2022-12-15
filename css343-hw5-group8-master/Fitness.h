//
// Created by Olive on 8/3/2022.
//

#ifndef FITNESS_H
#define FITNESS_H

#include "Puzzle.h"
#include "Sudoku.h"

using namespace std;

class Fitness {
public:
    /**
     * count the total number of conflicts in a puzzle
     * @param puzzle a puzzle to find fitness for
     * @return an integer representing fitness, lower is better
     */
    virtual int howFit(Sudoku& puzzle) = 0;

};

#endif //FITNESS_H
