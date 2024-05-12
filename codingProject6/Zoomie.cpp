#include "Zoomie.h"
//
// Created by amytx on 5/9/2024.
//

//FIXME: consider if we need this constructor. Why can't we just use the constructor from the base class?
Zoomie::Zoomie(World* world, int x, int y){
    this->x = x;
    this->y = y;
    this->breedTicks = 0;
    this->world = world;
    this->world->setAt(x,y,this); //setting the position of the organism to x , y

}

//FIXME: consider if we need this destructor. Why can't we just use the destructor from the base class?
Zoomie::~Zoomie(){
    std::cout <<" entering Zoomie::~Zoomie() ...\n";
    if (world!=nullptr){
        delete world;
        world = nullptr;
    }
}

//FIXME: consider if we need copy constructor. Why can't we just use the copy constructor from the base class?
Zoomie::Zoomie (const Zoomie& zoom) {
    this->world = zoom.world;
    this->x = zoom.x;
    this->y = zoom.y;
    this->breedTicks = zoom.breedTicks;
    this->moved = zoom.moved;
}

//breed every 3 ticks
//If the Zoomie breeds, it creates a new Zoomie in an adjacent cell where there is an empty cell.
// If there is no empty cell, then no breeding occurs.
void Zoomie::breed(){
    if(breedTicks == 3){ //if breedTicks is 3
        breedTicks = 0; //reset breedTicks
        //find an empty cell to breed from the current cell
        int newX = x;
        int newY = y;
        int direction = rand() % 4; // 0 is right, 1 is left, 2 is up, 3 is down
        switch (direction) {
            case 0: //right
                newX = x + 1;
                break;
            case 1: //left
                newX = x - 1;
                break;
            case 2: //up
                newY = y + 1;
                break;
            case 3: //down
                newY = y - 1;
                break;
        }
        if (world->isValid(newX, newY) && world->getAt(newX, newY) == nullptr) { //if the new position is valid and empty
            Zoomie* newZoomie = new Zoomie(world, newX, newY); //create a new Zoomie
        }
        //if the new position is not valid or not empty, then no breeding occurs
    }
};

//Randomly try to move up, down, left, or right.
// If the neighboring cell in the selected direction is occupied or would move the Zoomie off the grid,
//      then the Zoomie stays in the current cell.
void Zoomie::move(){
    moved = true; //set moved to true
    breedTicks++; //increment breedTicks

    //rand() generates a random number from 0 to 2147483647;
    int direction = rand() % 4; // 0 is right, 1 is left, 2 is up, 3 is down
    int newX = x;
    int newY = y;
    switch (direction) {
        case 0: //move right
            newX = x + 1;
            break;
        case 1: //move left
            newX = x - 1;
            break;
        case 2: //up
            newY = y + 1;
            break;
        case 3: //down
            newY = y - 1;
            break;
    }
    if (world->isValid(newX, newY) && world->getAt(newX, newY) == nullptr) { //if the new position is valid and empty
        world->setAt(newX, newY, this); //set the new position to the Zoomie
        world->setAt(x, y, nullptr); //set the old position to empty
        x = newX; //update the x position
        y = newY; //update the y position
    }

};

int Zoomie::getType(){
    return 1; //1 is Zoomie
}

//Zoomie never starves
bool Zoomie::starve(){
    return false;
}

