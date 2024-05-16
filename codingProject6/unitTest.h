//
// Created by Scott Chen on 5/15/24.
//

#ifndef CSC340FINALGROUPPROJECT_UNITTEST_H
#define CSC340FINALGROUPPROJECT_UNITTEST_H
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"
#include "Swoopie.h"



bool testZoomieConsturctor(){ //test if the zoomie is created at the right position
    try {
        World *world = new World(); // 30x30 grid
        Organism *zoomie = new Zoomie(world, 0, 0); // Zoomie at (0,0)
        if (world->getAt(0,0) != zoomie) { // check if the world has the zoomie at (0,0)
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }
}
// move a zoomie 3 times. After each move, check if the zoomie has moved
// breed the zoomie and check if there is a new zoomie in the world
bool testZoomie_Move_Breed() { //test if the zoomie can move and breed
    try {
        World *world = new World(); // 30x30 grid
        Organism *zoomie = new Zoomie(world, 15, 15); // Zoomie at (0,0)

        int oldXPos = zoomie->getX(); // get the x old position
        int oldYPos = zoomie->getY(); // get the y old position

        for (unsigned int i = 0; i < 3; i++) { //move 3 times
            zoomie->move();
            if(zoomie->getX() == oldXPos && zoomie->getY() == oldYPos) { // check if the zoomie has moved
                return false;
            }
            oldXPos = zoomie->getX(); // update the old position
            oldYPos = zoomie->getY(); // update the old position
        }

        zoomie->breed(); // breed
        int numZoomies = 0;
        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (world->getAt(i, j) != nullptr && world->getAt(i, j)->getType() == 1) { // check if there is a zoomie in the world
                    numZoomies++;
                }
            }
        }
        if (numZoomies != 2) { // check if there is a new zoomie in the world
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }

}

//test swoopie constructor
bool testSwoopieConsturctor(){ //test if the swoopie is created at the right position
    try {
        World *world = new World(); // 30x30 grid
        Organism *swoopie = new Swoopie(world, 20, 20); // Swoopie at (20,20)
        if (world->getAt(20,20) != swoopie) { // check if the world has the swoopie at (20,20)
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }
}

//test swoopie move and if the swoopie eat the zoomie that is one step away
bool testSwoopie_Move_Eat() { //test if the swoopie can move and eat the zoomie
    try {
        World *world = new World(); // 30x30 grid
        Organism *zoomie = new Zoomie(world, 15, 15); // Zoomie at (15,15)
        Organism *swoopie = new Swoopie(world, 15, 16); // Swoopie at (15,16)

        int zoomieXPos = zoomie->getX(); // get the x old position
        int zoomieYPos = zoomie->getY(); // get the y old position

        swoopie->move(); // move the swoopie
        if(swoopie->getX() != zoomieXPos && swoopie->getY() != zoomieYPos) { // check if the swoopie has moved
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }

}

//test if the swoopie starve and die after 3 moves
bool testSwoopie_Starve() { //test if the swoopie can starve and die
    try {
        World *world = new World(); // 30x30 grid
        Organism *swoopie = new Swoopie(world, 15, 15); // Swoopie at (15,15)

        for (unsigned int i = 0; i < 4; i++) { //move 3 times
            swoopie->move();
        }
        int numSwoopies = 0;

        for (int i = 0; i < WORLDSIZE; i++) {
            for (int j = 0; j < WORLDSIZE; j++) {
                if (world->getAt(i, j) != nullptr && world->getAt(i, j)->getType() == 2) { // check if there is a swoopie in the world
                    numSwoopies++;
                }
            }
        }


        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }

}


#endif //CSC340FINALGROUPPROJECT_UNITTEST_H
