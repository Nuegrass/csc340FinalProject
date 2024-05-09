//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_WORLD_H
#define CSC340FINALGROUPPROJECT_WORLD_H

#include "Organism.h"
class World
{
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
private:
    Organism* grid[30][30];  //WORLDSIZE=30
};


#endif //CSC340FINALGROUPPROJECT_WORLD_H
