#ifndef SUDOKU_FITNESS
#define SUDOKU_FITNESS

#include "Fitness.h"
#include "Sudoku.h"

using namespace std;

class SudokuFitness : virtual Fitness {
public:

    /**
     * count the total number of conflicts in a puzzle:
     * how many duplicate entries there are in each row, column, and 3x3 block.
     * Each duplicate pair will count as two conflicts (not just one):
     * eg. two 3s in the same row would increase the fitness by 2,
     * three 3s in the same row would increase the fitness by 6,
     * and two 3s in the same row and block would increase the fitness by 4.
     * @param p a sudoku to find fitness for
     * @return an integer representing fitness, lower is better
     */
    int howFit(Sudoku& p);

    /**
     * @param conflicts whether there are two of any given digit conflicting in their group
     * @param total the total conflicts in a group
     * @return the total score for this group
     */
    int helper(int conflicts[], int total);
};

#endif //SUDOKU_FITNESS
