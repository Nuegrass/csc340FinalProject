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
    virtual void breed() ;       // Whether or not to breed
    virtual void move() ;        // Rules to move the critter
    virtual int getType() ;       // Return if Swoopie or Zoomie
    virtual bool starve() ;      // Determine if organism starves
protected:


};
#endif //CSC340FINALGROUPPROJECT_ZOOMIE_H
