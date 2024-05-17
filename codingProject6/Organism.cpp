//
// Created by amytx on 5/9/2024.
// assist by GitHub Copilot
#include "Organism.h"

Organism::Organism(){
    //default constructor
}

Organism::Organism(World *world, int x, int y){
    this->x = x;
    this->y = y;
    this->breedTicks = 0;
    this->moved = false;
    this->world = world;//points the organism to the world
}

Organism::~Organism(){
        std::cout <<" entering Organism::~Organism() ...\n";
        if (world!=nullptr){
            delete[] world;
            world = nullptr;
        }
}

void Organism::breed() {
    //to be overridden by derived classes
}

void Organism::move(){
    //to be overridden by derived classes
}
int Organism::getType() {
    //to be overridden by derived classes
    return 0;  // 1 is Zoomie, 2 is Swoopie
}
bool Organism::starve(){
    //to be overridden by derived classes
    return false;
}
