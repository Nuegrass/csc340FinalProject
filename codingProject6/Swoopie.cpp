//
// Created by amytx on 5/9/2024.
//
#include "Swoopie.h"

//FIXME: Need correction here
Swoopie::Swoopie(World *world, int x, int y) {
    this->x = x;
    this->y = y;
    this->breedTicks = 0;
    this->moved = false;
    this->starveTicks = 0;

    this->world = world;//points the organism to the world
    this->world->setAt(x,y,this); //setting the position of the organism to x , y

}
//FIXME: Need correction here
Swoopie::~Swoopie() {
    std::cout << "entering Swoopie::~Swoopie() ...\n";
    if (world != nullptr) {
        delete[] world;
        world = nullptr;
    }
}

// copy constructor
Swoopie::Swoopie(const Swoopie &toBeCopy) {
    this->world = toBeCopy.world;
    this->x = toBeCopy.x;
    this->y = toBeCopy.y;
    this->breedTicks = toBeCopy.breedTicks;
    this->moved = toBeCopy.moved;
}
// copy assignment operator
Swoopie Swoopie::operator=(const Swoopie &rhs) {
    if (this != &rhs) {
        this->world = rhs.world;
        this->x = rhs.x;
        this->y = rhs.y;
        this->breedTicks = rhs.breedTicks;
        this->moved = rhs.moved;
    }
    return *this;
}
//If a Swoopie survives for eight time steps, then at the end of the time step it will spawn off a new Swoopie in the same manner as the Zoomie.
void Swoopie::breed() {
    if (breedTicks == 8) {
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
            new Swoopie(world, newX, newY); //create a new Swoopie

        }
        //if the new position is not valid or not empty, then no breeding occurs
    }
}
//FIXME: check Memory leak here
void Swoopie::move() {

    moved = true; //set moved to true
    breedTicks++; //increment breedTicks
    starveTicks++; //increment starveTicks

    //check if there is a Zoomie in the adjacent cells
    if (isZoomie(x, y + 1)) { // if there is a Zoomie below
        starveTicks = 0; //reset starveTicks
        world->setAt(x, y + 1, this);
        world->setAt(x, y, nullptr);
        y++;
    } else if (isZoomie(x, y - 1)) { // if there is a Zoomie above
        starveTicks = 0; //reset starveTicks
        world->setAt(x, y - 1, this);
        world->setAt(x, y, nullptr);
        y--;
    } else if (isZoomie(x + 1, y)) { // if there is a Zoomie to the right
        starveTicks = 0; //reset starveTicks
        world->setAt(x + 1, y, this);
        world->setAt(x, y, nullptr);
        x++;
    } else if (isZoomie(x - 1, y)) { // if there is a Zoomie to the left
        starveTicks = 0; //reset starveTicks
        world->setAt(x - 1, y, this);
        world->setAt(x, y, nullptr);
        x--;
    } else {

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
    }


    breed();
    starve();

}

//If a Swoopie has not eaten a Zoomie within the last three time steps, then at the end of the third time step it will starve and die. The
//Swoopie should then be removed from the grid of cells
//FIXME: check for Memory leak here
bool Swoopie::starve() {
    if (starveTicks == 3) {
        starveTicks = 0;
        world->setAt(x, y, nullptr);
        return true;
    }
    return false;
}
int Swoopie::getType() {
    return 2; // 1 is Zoomie, 2 is Swoopie
}

//helper function
bool Swoopie::isZoomie(int x, int y) {
    //check if x and y are [0,30]
    if(world->isValid(x, y) && (world->getAt(x, y) != nullptr)){
        if(world->getAt(x, y)->getType() == 1){
            return true;
        }
    }
    return false;
}
std::string Swoopie::toString() {
    std::string tmp;
    int tmpX = this->x;
    int tmpY = this->y;
    tmp = "xPos : " + std::to_string(tmpX) + " yPos : " +std::to_string(tmpY) ;
    return tmp;
}