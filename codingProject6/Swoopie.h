//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_SWOOPIE_H
#define CSC340FINALGROUPPROJECT_SWOOPIE_H

#include "Organism.h"
#include "World.h"
//we  #include World.h because we want to use the member functions of world in our cpp definitions
class Swoopie : public Organism {
    friend class Zoomie;
public:
    Swoopie(World *world, int x, int y);

    ~Swoopie();//destructor
    Swoopie(const Swoopie &zoom);//copy constructor
    Swoopie operator=(const Swoopie &swooper);//copy assignment operator
    Swoopie();//constructor
    void breed() override;       // Whether to breed
    void move() override;        // Rules to move the critter
    int getType() override;       // Return if Swoopie or Swoopie
    bool starve() override;      // Determine if organism starves
    std::string toString();
    //helper functions
    bool isZoomie(int x, int y);
protected:
    int starveTicks;
};
#endif //CSC340FINALGROUPPROJECT_SWOOPIE_H
