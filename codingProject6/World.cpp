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

}
Organism* World::getAt(int x, int y){
        Organism* tmp = nullptr;
        tmp = this->grid[x][y];
        return tmp;
    }  //return a pointer to the critter at position [x][y]
void World::setAt(int x, int y, Organism *org){
   grid[x][y] = org;
    //  Organism* grid[WORLDSIZE][WORLDSIZE]
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
