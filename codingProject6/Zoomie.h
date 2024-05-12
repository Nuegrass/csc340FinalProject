//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_ZOOMIE_H
#define CSC340FINALGROUPPROJECT_ZOOMIE_H

#include "Organism.h"
class Zoomie : public Organism{

public:
    Zoomie(World *world, int x, int y);

    ~Zoomie();//destructor
    Zoomie (const Zoomie& zoom );//copy constructor
    Zoomie& operator=(const Zoomie& zoomer);//copy assignment operator
    Zoomie();//constructor
    void breed() override ;       // Whether to breed
    void move() override ;        // Rules to move the critter
    int getType() override ;       // Return if Swoopie or Zoomie
    bool starve() override ;      // Determine if organism starves
    std::string toString();

protected:
//doesn't need any protected variables because they don't need extras outside the one provided
//by organism

};
#endif //CSC340FINALGROUPPROJECT_ZOOMIE_H
