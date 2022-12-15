#include <iostream>
#include <ostream>
#include <istream>
#include "Puzzle.h"

/**
 * takes in a puzzle to put in
 * @param
 * @return output stream of
 */
ostream& operator<<(ostream& os, const Puzzle& puzzle) {
    return puzzle.output(os);
}

/**
 * in stream
 * @param puzzle to print
 * @return input stream
 */
istream& operator>>(istream& in, Puzzle& puzzle) {
    return puzzle.input(in);
}
