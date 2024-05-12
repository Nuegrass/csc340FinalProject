//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_WORLD_H
#define CSC340FINALGROUPPROJECT_WORLD_H

class Organism;
#include <random>

const int WORLDSIZE = 30;

class World {
    friend class Organism;                // Allow Organism to access grid
    friend class Swoopie;                 // Allow Organism to access grid
    friend class Zoomie;                  // Allow Organism to access grid
public:
    World();
    ~World();
    Organism* getAt(int x, int y);  //return a pointer to the critter at position [x][y]
    void setAt(int x, int y, Organism *org);
    void Display();                 //display the grid
    void SimulateOneStep();         //simulate one step

    //helper functions
    bool isValid(int newX, int newY); // check (newX, newY) is in 30x30 grid;

    //FIXME: not sure if we need this function
    //void genRandPosForOrangnism(int& newX, int& newY, Organism* organism);

private:

    Organism* grid[WORLDSIZE][WORLDSIZE];  //WORLDSIZE=30
};

#endif //CSC340FINALGROUPPROJECT_WORLD_H
