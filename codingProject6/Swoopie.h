//
// Created by amytx on 5/9/2024.
//

#ifndef CSC340FINALGROUPPROJECT_SWOOPIE_H
#define CSC340FINALGROUPPROJECT_SWOOPIE_H
#include "Organism.h"
class Swoopie : public Organism {
    friend class Zoomie;
public:

    Swoopie(World *world, int x, int y);
    virtual ~Swoopie();
    Swoopie(const Swoopie& toBeCopy);
    Swoopie operator=(const Swoopie& rhs);

    virtual void breed();       // Whether or not to breed
    virtual void move();        // Rules to move the Swoopie
    virtual int getType();       // Return if Swoopie or Zoomie
    virtual bool starve();

    //helper functions
    bool isZoomie(int x, int y);

protected:
    int starveTicks;
};



#endif //CSC340FINALGROUPPROJECT_SWOOPIE_H
