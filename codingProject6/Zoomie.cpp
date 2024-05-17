#include "Zoomie.h"

//
// Created by amytx on 5/9/2024.
// assist by GitHub Copilot

Zoomie::Zoomie(){
    //default constructor
}
Zoomie::Zoomie(World* world, int x, int y){//parameterized constructor
    this->x = x;
    this->y = y;
    this->moved = true; //set moved to true since when new Zoomie is bred, it is considered moved
    this->breedTicks = 0;
    this->world = world;
    this->world->setAt(x,y,this);

}

//if the Zoomie has moved 3 times, find an empty adjacent cell to breed from the current cell
// no breeding if there is no empty adjacent cell
void Zoomie::breed() {
    breedTicks = 0; //reset breedTicks

    //find an empty adjacent cell to breed from the current cell
    int newX = x;
    int newY = y;
    std::random_device rd;
    std::mt19937 generator(rd()); // Seed the generator
    std::uniform_int_distribution<> distribution(0,3);// to generate a random number from 0-3
    int direction = distribution(generator); // 0 is right, 1 is left, 2 is up, 3 is down
    //default direction is right
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
        world->getAt(newX, newY); // create and put new Zoomie into the world

    }

};

//make a random move (left, right, up, down), and stay if the cell that it is moving to is invalid or occupied
//if the Zoomie has moved 3 times, then it breeds
void Zoomie::move(){
    moved = true; //set moved to true

    std::random_device rd;
    std::mt19937 generator(rd()); // Seed the generator
    std::uniform_int_distribution<> distribution(0,3);// to generate a random number from 0-3
    int direction = distribution(generator); // 0 is right, 1 is left, 2 is up, 3 is down

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
    breedTicks++; //increment breedTicks since moved

    if (breedTicks == 3) {
        breed(); //breed if moved 3 times
    }
};

int Zoomie::getType(){
    return 1; // 1 is Zoomie, 2 is Swoopie
}

bool Zoomie::starve(){ //Zoomie never starve
    return false;
}

Zoomie::~Zoomie() {//destructor
    std::cout <<" entering Zoomie::~Zoomie() ...\n";
    if (world!=nullptr){
        delete[] world;
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


