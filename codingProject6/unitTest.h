//
// Created by Scott Chen on 5/15/24.
// assist by GitHub Copilot

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

        for (unsigned int i = 0; i < 3; i++) { //move 3 times
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

        if (numSwoopies != 0) { // check if the swoopie has died
            std::cout << "numSwoopies: " << numSwoopies << std::endl;
            return false;
        }

        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }

}

//test world at getAt()
bool testWorldAt() {
    try {
        World *world = new World(); // 30x30 grid
        Organism *zoomie = new Zoomie(world, 15, 15); // Zoomie at (15,15)
        if (world->getAt(15, 15) != zoomie) { // check if the world has the zoomie at (15,15)
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return false;
    }
}


//test all unit test
void callAllUnitTests(){
    //unit tests
    if (testZoomieConsturctor()) {
        std::cout << "Zoomie Constructor Test Passed" << std::endl;
    } else {
        std::cout << "Zoomie Constructor Test Failed" << std::endl;
    }

    //test testZoomie_Move_Breed()
    if (testZoomie_Move_Breed()) {
        std::cout << "Zoomie Move and Breed Test Passed" << std::endl;
    } else {
        std::cout << "Zoomie Move and Breed Test Failed" << std::endl;
    }

    //test testSwoopieConsturctor()
    if (testSwoopieConsturctor()) {
        std::cout << "Swoopie Constructor Test Passed" << std::endl;
    } else {
        std::cout << "Swoopie Constructor Test Failed" << std::endl;
    }
    // test testSwoopie_Starve()
    if (testSwoopie_Starve()) {
        std::cout << "Swoopie Starve Test Passed" << std::endl;
    } else {
        std::cout << "Swoopie Starve Test Failed" << std::endl;
    }

    // test testSwoopie_Move_Eat()
    if (testSwoopie_Move_Eat()) {
        std::cout << "Swoopie Move and Eat Test Passed" << std::endl;
    } else {
        std::cout << "Swoopie Move and Eat Test Failed" << std::endl;
    }

    // test testWorldAt()
    if (testWorldAt()) {
        std::cout << "World getAt() Test Passed" << std::endl;
    } else {
        std::cout << "World getAt() Test Failed" << std::endl;
    }


}



#endif //CSC340FINALGROUPPROJECT_UNITTEST_H
