#include "SudokuFactory.h"
#include "SudokuOffspring.h"

using namespace std;

/**
 * create a puzzle
 * @param p a source puzzle to base off of
 * @return a Sudoku* with similar but randomized traits
 */
Sudoku* SudokuFactory::createPuzzle(Sudoku* p) {

    return offspring->makeOffspring(p);
}
