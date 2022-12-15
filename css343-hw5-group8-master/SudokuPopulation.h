#ifndef SUDOKU_POPULATION_H
#define SUDOKU_POPULATION_H

#include "Population.h"
#include "Fitness.h"
#include "PuzzleFactory.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"

using namespace std;

class SudokuPopulation : public Population {
public:
    /**
     *
     * @param populationSize
     * @param puzzle
     */
    SudokuPopulation(int populationSize, Sudoku* puzzle);

    /**
     *
     */
    ~SudokuPopulation() {
        delete factory;
        delete fitness;
        for (auto& individual: puzzles)
            delete individual.second;
    };

    /**
     *
     * @param percent
     */
    void cull(double percent) override;

    /**
     *
     */
    void newGeneration() override;

    /**
     *
     * @return
     */
    int bestFitness() override;

    /**
     *
     * @return
     */
    Individual bestIndividual() override;

private:
    SudokuFactory* factory = new SudokuFactory(); // puzzle factory class
    SudokuFitness* fitness = new SudokuFitness(); // puzzle fitness class
};


#endif //SUDOKU_POPULATION_H
