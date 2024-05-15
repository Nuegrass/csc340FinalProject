//
// Created by amytx on 5/9/2024.
//
#include "Organism.h"

Organism::Organism(){

}
Organism::Organism(World *world, int x, int y){
    this->x = x;
    this->y = y;
    this->breedTicks = 0;
    this->world = world;//points the organism to the world

    //this->world->setAt(x,y,this); //setting the position of the organism to x , y
    //^^^^^^TOTALLY UNNECCE`SARY BECAUSE WE USE SETAT IN MAIN
    //but then that brings another quesiton, do we need to use any more of the memeber
    //functions for world in this organism class?????
    //I CHECKED SCOTTS AND DOESNT LOOK LIKE IT LUL
}

Organism::~Organism(){
        std::cout <<" entering Organism::~Organism() ...\n";
        if (world!=nullptr){
            delete[] world;
            world = nullptr;
        }

}
void Organism::breed() {

}      // Whether or not to breed
void Organism::move(){
    breedTicks++;
}        // Rules to move the critter
int Organism::getType() {
}      // Return if Swoopie or Zoomie
bool Organism::starve(){
    return false;
}   //
