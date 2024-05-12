//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_ORGANISM_H
#define CSC340FINALGROUPPROJECT_ORGANISM_H

#include <iostream>
class World;
class Organism
{
    friend class World;                     // Allow world to affect organism
public:
    Organism();
    Organism(World *world, int x, int y);
    ~Organism();
    virtual void breed() = 0;       // Whether or not to breed
    virtual void move() = 0;        // Rules to move the critter
    virtual int getType() =0;       // Return if Swoopie or Zoomie
    virtual bool starve() = 0;      // Determine if organism starves
protected:
    int x,y;                        // Position in the world
    bool moved;                     // Bool to indicate if moved this turn
    int breedTicks;                 // Number of ticks since breeding
    World *world;
};
#endif //CSC340FINALGROUPPROJECT_ORGANISM_H
