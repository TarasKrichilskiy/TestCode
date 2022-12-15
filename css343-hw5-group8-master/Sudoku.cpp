#include "Sudoku.h"

istream& Sudoku::input(istream& in) {
    grid.clear(); //make a new grid
    char c;
    while (in >> c) {
        if (isdigit(c)) {
            pair<int, bool> temp = {c - '0',c != '0'}; // converting char to int
            grid.push_back(temp);
        }
        if (grid.size() == 81) {
            return in; //if full, end the istream in
        }
    }
    return in;
}

ostream& Sudoku::output(ostream& out) const {
    out << "+-------+-------+-------+\n";
    for (int i = 0; i < 9; ++i) {
        out << "|";
        for (int j = 0; j < 9; ++j) {
            out << " " << grid[i * 9 + j].first;
            if (j % 3 == 2) {
                out << " |";
            }
        }
        out << endl;
        if (i % 3 == 2) {
            out << "+-------+-------+-------+\n";
        }
    }
    return out;
}

Sudoku::Sudoku() {
    grid.resize(81);
}

// constructor copy
Sudoku::Sudoku(Sudoku& copy) {
    this->grid = copy.grid;
}

// copy and return
Sudoku* Sudoku::copy(Sudoku& copy) {
    this->grid = copy.grid;
    return this;
}

//get value with r = row , c= column
int Sudoku::value(int r, int c) {
    return grid[r * 9 + c].first;
}

//get determinent with r = row , c= column
bool Sudoku::determinent(int r, int c) {
    return grid[r * 9 + c].second;
}

void Sudoku::setValue(int r, int c, int val, bool deter) {
    pair<int, bool> temp = {val, deter};
    grid[r * 9 + c] = temp;
}
