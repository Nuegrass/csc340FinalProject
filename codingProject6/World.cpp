//
// Created by amytx on 5/9/2024.
//

#include "World.h"
World::World(){
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            grid[i][j] = nullptr;
        }
    }
}
World::~World(){
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if(grid[i][j] != nullptr){
                delete grid[i][j];
            }
        }
    }
}
Organism* World::getAt(int x, int y){
    if (this->grid[x][y] == nullptr){
        return nullptr;
    }else{
        Organism* tmp = this->grid[x][y];
        return tmp;

    }
}  //return a pointer to the critter at position [x][y]

void World::setAt(int x, int y, Organism *org) {
    grid[x][y] = org;
}
void World::Display(){
    std::cout <<"Entering Display() function"<< std::endl;

    //loop through the grid and display the grid
    // "_" is empty cell, "o" is Zoomie, "x" is Swoopie
    for(int i = 0; i < WORLDSIZE; i++){
        for(int j = 0; j < WORLDSIZE; j++){
            if(grid[i][j] == nullptr){
                std::cout << "_";
            }else if(grid[i][j]->getType() == 1){//1 is zoomie and 2 is swoopie
                std::cout << "o";
            }else if(grid[i][j]->getType() == 2){
                std::cout << "x";
            }
        }
        std::cout << std::endl; //new line
    }
}

// 1. set all organisms to  "moved = false", have not moved
// 2. move all swoopies first
// 3. move all zoomies
void World::SimulateOneStep(){
    std::cout << "simulating one step" << std::endl;

    //set all organisms are not moved
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr){
                grid[i][j]->moved = false;
            }
        }
    }

    //move all swoopies
    // getType():  1 is zoomie and 2 is swoopie
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr && (int)grid[i][j]->getType() == 2 && !grid[i][j]->moved){ //if the organism is swoopie and has not moved
                grid[i][j]->move();
            }
        }
    }
    //move all zoomies
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr && (int)grid[i][j]->getType() == 1 && !grid[i][j]->moved){ //if the organism is zoomie and has not moved
                grid[i][j]->move();

            }
        }
    }
}

//helper functions
bool World::isValid(int x, int y){ // check (newX, newY) is in 30x30 grid; but x in [0,29] and y in [0,29]

    if(x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE){
        return true;
    }else{
        return false;
    }
}
