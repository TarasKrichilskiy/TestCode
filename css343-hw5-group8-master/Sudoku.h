#ifndef SUDOKU
#define SUDOKU

#include <vector>
#include "Puzzle.h"

using namespace std;

class Sudoku : public Puzzle {
public:

    /**
     * constructor
     */
    Sudoku();

    /**
     * copy constructor
     */
    Sudoku(Sudoku& copy);

    /**
     * populate the sudoku with digits
     * @param in an istream containing digits to read in
     * @return pass on the istream for other objects to intake
     */
    istream& input(istream& in) override;

    /**
     * output a text of sudoku
     * @param out
     * @return
     */
    ostream& output(ostream& out) const override;

    /**
     * the digit stored at a location in the grid
     * @param r the row
     * @param c the column
     * @return the digit
     */
    int value(int r, int c);

    /**
     * whether the digit at a location in the grid is original
     * @param r the row
     * @param c the column
     * @return the originality of the digit
     */
    bool determinent(int r, int c);

    /**
     * @param r the row
     * @param c the column
     * @param val the value to set
     * @param deter whether the digit is original
     */
    void setValue(int r, int c, int val, bool deter);

    // vector of Sudoku, to find the position the equation is grid[x*9+y]
    // the first is the number in position, second is if it's the original number
    vector <pair<int, bool>> grid;
};

#endif
