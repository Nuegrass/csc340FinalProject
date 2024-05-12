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
        Organism* tmp = nullptr;
        tmp = this->grid[x][y];
        return tmp;
    }  //return a pointer to the critter at position [x][y]

void World::setAt(int x, int y, Organism *org){
   grid[x][y]=org;

}





void World::Display(){
//    for(int i =0; i < WORLDSIZE; i++){
//        for(int j = 0; j < WORLDSIZE; j++){
//            if(grid[i][j]->getType() == 1){//1 is zoomie and 2 is swoopie
//                std::cout << "o";
//            }else if(grid[i][j]->getType() == 2){
//                std::cout << "x";
//            }else
//                std::cout << "_";
//
//        }
//        std::cout << std::endl;
//    }
}                 //display the grid
void World::SimulateOneStep(){
}


//helper functions

bool World::isValid(int x, int y){
    if(x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE){
        return true;
    }else{
        return false;
    }
} // check (x,y) is in 30x30 grid

//FIXME: not sure if we need this function
//void World::genRandPosForOrangnism(int &x, int &y) {
//    int direction = rand() % 4; // 0 is right, 1 is left, 2 is up, 3 is down
//    switch (direction) {
//        case 0: //move right
//            newX = x + 1;
//            break;
//        case 1: //move left
//            newX = x - 1;
//            break;
//        case 2: //up
//            newY = y + 1;
//            break;
//        case 3: //down
//            newY = y - 1;
//            break;
//    }
//}

