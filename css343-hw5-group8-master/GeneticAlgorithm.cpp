#include <bits/stdc++.h>
#include "GeneticAlgorithm.h"

using namespace std;

/**
 * constructor
 * @param maxGeneration max number of generation before ending operation
 * @param populationSize the number of puzzles to create each generation
 * @param initialSudoku the initial sudoku to solve
 */
GeneticAlgorithm::GeneticAlgorithm(int maxGeneration, int populationSize,
                                   Sudoku* initialSudoku) {
    this->maxGeneration = maxGeneration;
    population = new SudokuPopulation(populationSize, initialSudoku);
}

/**
 * run the algorithm to try and get the solution
 * @return an Individual containing the solution
 */
Individual GeneticAlgorithm::run() {

    Individual best(INT_MAX, nullptr);

    for (0; generationCount < maxGeneration; ++generationCount) {

        // current best Sudoku/individual
        Individual currentBest = population->bestIndividual();

        // if fitness is 0 means found the solution, best is found, return to main 
        if (currentBest.first == 0) {
            best = currentBest;
            break;
        }
        // if the fitness of current best is less than overall best, update
        if (currentBest.first < best.first) {
            best = currentBest;
        }

        // cull 90% individuals
        population->cull(0.9);
        // make new generation
        population->newGeneration();
    }

    return best;
}

/**
 * @return the current generation being run
 */
int GeneticAlgorithm::getGenerationCount() const {
    return generationCount;
}
