#include "Zoomie.h"

//
// Created by amytx on 5/9/2024.
//

Zoomie::Zoomie(){
    this->breedTicks = 0;
    this->moved = false;
}
Zoomie::Zoomie(World* world, int x, int y){//parameterized constructor
    this->x = x;
    this->y = y;
    this->moved = false;
    this->breedTicks = 0;
    this->world = world;
    this->world->setAt(x,y,this);
}
void Zoomie::breed() {
    if(breedTicks == 3){ //if moved 3 times
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
            new Zoomie(world, newX, newY); //create a new Zoomie
        }
        breedTicks = 0; //reset breedTicks
    }
};

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
    //if the new position is not valid or not empty, then no movement occurs

    breed(); //breed after moving

};        // Rules to move the critter
int Zoomie::getType(){
    return 1;
}       // Return if Swoopie or Zoomie
bool Zoomie::starve(){
    return false;

}

Zoomie::~Zoomie() {//destructor
    std::cout <<" entering Zoomie::~Zoomie() ...\n";
    if (world!=nullptr){
        delete world;
        world = nullptr;
    }
}

Zoomie::Zoomie(const Zoomie &zoom)  : Organism(zoom) {
    this->world = zoom.world;
    this->x = zoom.x;
    this->y = zoom.y;
    this->breedTicks = zoom.breedTicks;
    this->moved = zoom.moved;
}
std::string Zoomie::toString(){
    std::string tmp;
    int tmpX = this->x;
    int tmpY = this->y;
    tmp = "xPos : " + std::to_string(tmpX) + " yPos : " +std::to_string(tmpY) ;
    return tmp;
}

/*Zoomie &Zoomie::operator=(const Zoomie &zoomer) {
    return <#initializer#>;
}*/
// Determine if organism starves

