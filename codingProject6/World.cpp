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
void World::setAt(int x, int y, Organism *org){
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
            }else
                std::cout << "_";

        }
        std::cout << std::endl;
    }
}                 //display the grid
void World::SimulateOneStep(){
    std::cout << "simulating one step" << std::endl;
}
//helper functions

bool World::isValid(int x, int y){
    if(x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE){
        return true;
    }else{
        return false;
    }
} // check (x,y) is in 30x30 grid
