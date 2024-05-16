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
    //std::cout << grid[0][0]->getType();
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
        std::cout << std::endl;
    }
}                 //display the grid
void World::SimulateOneStep(){
    std::cout << "simulating one step" << std::endl;
    //move all swoopies first
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getType() == 2 && grid[i][j]->moved == false){
                if(!grid[i][j]->starve()){ //move if the Swoopie does not starve
                    grid[i][j]->move();
                }
            }

        }
    }

    //move all zoomies
    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr && grid[i][j]->getType() == 1 && grid[i][j]->moved == false){
                grid[i][j]->move();
            }
        }
    }

    for (int i = 0; i < WORLDSIZE; ++i) {
        for (int j = 0; j < WORLDSIZE; ++j) {
            if (grid[i][j] != nullptr){
                grid[i][j]->moved = false;
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
} // check (x,y) is in 30x30 grid
