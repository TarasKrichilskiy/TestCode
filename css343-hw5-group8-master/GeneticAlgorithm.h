#ifndef GENETIC_ALGORITHM
#define GENETIC_ALGORITHM

#include <bits/stdc++.h>
#include "Sudoku.h"
#include "SudokuPopulation.h"

using namespace std;

class GeneticAlgorithm {
public:
    /**
     * constructor
     * @param maxGeneration max number of generation before ending operation
     * @param populationSize the number of puzzles to create each generation
     * @param initialSudoku the initial sudoku to solve
     */
    GeneticAlgorithm(int maxGeneration, int populationSize, Sudoku* initialSudoku);

    /**
     * destructor
     */
    ~GeneticAlgorithm() {
        delete population;
    }

    /**
     * run the algorithm to try and get the solution
     * @return an Individual containing the solution
     */
    Individual run();

    /**
     * @return the current generation being run
     */
    int getGenerationCount() const;

private:
    int maxGeneration; // the maximum generations to run before halting
    int generationCount = 0; // the current generation being run
    Population* population; // a population to store puzzles
};

#endif //GENETIC_ALGORITHM
