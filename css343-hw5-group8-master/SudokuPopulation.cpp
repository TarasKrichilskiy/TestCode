#include "Sudoku.h"
#include "SudokuPopulation.h"
#include "PuzzleFactory.h"
#include "SudokuFitness.h"
#include <algorithm>

using namespace std;

SudokuPopulation::SudokuPopulation(int populationSize, Sudoku* puzzle) {
    PSize = populationSize;
    for (int i = 0; i < PSize; ++i) {
        Sudoku* p = factory->createPuzzle(puzzle);
        puzzles.emplace_back(fitness->howFit(*p), p);
    }
}

void SudokuPopulation::cull(double percent) {
    sort(puzzles.begin(),
         puzzles.end()); // sort all puzzles in  vector of all Individual
    int eliminateStartP = (int) ((1 - percent) * PSize);
    Individual pd;
    for(vector<Individual>::iterator it = puzzles.begin() + eliminateStartP; it != puzzles.end(); ++it) {
        pd = *it;
        delete pd.second;
    }
    puzzles.erase(puzzles.begin() + eliminateStartP, puzzles.end());
}

// generate next generation from current generation
void SudokuPopulation::newGeneration() {
    int puzzlesLeft = puzzles.size();
    int i = 0;
    while (puzzles.size() < PSize) {
        Sudoku* p;
        p = factory->createPuzzle(puzzles[i].second);
        puzzles.emplace_back(fitness->howFit(*p), p);

        if (i + 1 == puzzlesLeft) {
            i = 0;
        } else {
            i = i + 1;
        }
    }
}

// get best fitness from current generation
int SudokuPopulation::bestFitness() {
    vector<Individual>::iterator it = min_element(puzzles.begin(),
                                                  puzzles.end());
    return it->first;
}

// get best indiviual of current generation
Individual SudokuPopulation::bestIndividual() {
    return *min_element(puzzles.begin(), puzzles.end());
}

