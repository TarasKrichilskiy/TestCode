//
// Created by Olive on 8/3/2022.
//

#ifndef POPULATION_H
#define POPULATION_H

#include "Fitness.h"
#include "PuzzleFactory.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include <vector>

using namespace std;
using Individual = pair<int, Sudoku*>; // <fitness, Sudoku*>

/**
 * The Population class is the a container for a population. Every new generation gets
 * a specified size population. Each Individual member of a population is given
 * a fitness score to determine its position in the population. The top Individuals
 * with the best fitness scores are used for the next generation.
 */
class Population {
public:
    /**
     * destructor
     */
    ~Population() {
        delete factory;
        delete fitness;
    }

    /**
     * eliminate the X% least fit members of a generation
     * @param percent the percentage of individuals to cull
     */
    virtual void cull(double percent) = 0;

    /**
     * produce a new generation output of the old generation
     * presumably after the old generation has been culled,
     * so that the population size stays constant between generations
     * @param individuals the number of children to create for each individual
     * remaining of the old generation
     */
    virtual void newGeneration() = 0;

    /**
     * @return the fitness of the best Puzzle input the current generation
     */
    virtual int bestFitness() = 0;

    /**
     * @return the Individual with the highest fitness
     */
    virtual Individual bestIndividual() = 0;


protected:
    int PSize; // origional population size
    vector<Individual> puzzles; //list of puzzles
    PuzzleFactory* factory; // puzzle factory class
    SudokuFitness* fitness; // puzzle fitness class

};

#endif //POPULATION_H
