#include <iostream>
#include <string>
#include "Sudoku.h"
#include "SudokuPopulation.h"
#include "GeneticAlgorithm.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3 || argc > 3) {
        cout << "2 parameters expected, exiting" << endl;
        return 1;
    }
    int populationSize = stoi(argv[1]);
    int maxGenerations = stoi(argv[2]);

    // get the first puzzle
    Sudoku* puzzle = new Sudoku();
    cout << "population size is " << populationSize << endl <<
              "max generations is " << maxGenerations << endl << endl <<
              "enter 81 numbers" << endl;
    cin >> *puzzle;
    cout << *puzzle;

    // initial GA with max generation, population size and initial puzzle
    GeneticAlgorithm ga(maxGenerations, populationSize, puzzle);

    //get the best puzzle
    Individual best = ga.run();

    // output result
    if (best.first == 0)
        cout << "Puzzle was solved correctly in " << ga.getGenerationCount()
             << " generations: " << endl;
    else
        cout << "Best puzzle after " << maxGenerations
             << " generations was incorrect, fitness of " << best.first << ':'
             << endl;
    cout << *best.second;

    delete puzzle;
    return 0;
}


