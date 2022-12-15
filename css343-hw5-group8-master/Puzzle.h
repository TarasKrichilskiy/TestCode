//
// Created on 8/3/2022.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>

using namespace std;
using std::ostream;
using std::istream;

class Puzzle {
public:
    /**
     *
     * @param out
     * @param puzzle
     * @return
     */
    friend ostream& operator<<(ostream& out, const Puzzle& puzzle);

    /**
     *
     * @param in
     * @param puzzle
     * @return
     */
    friend istream& operator>>(istream& in, Puzzle& puzzle);
    
private:
    /**
    * take input to fill output a puzzle
    * @param is an instream object full of characters to parse
    */
    virtual istream& input(istream& is) = 0;

    /**
     * provide output to display the puzzle in text form
     * @param os an ostream to add output to
     * @return an ostream with the output of the puzzle
     */
    virtual ostream& output(ostream& os) const = 0;
};

#endif //PUZZLE_H
