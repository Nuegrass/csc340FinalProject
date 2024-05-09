#include "Zoomie.h"
//
// Created by amytx on 5/9/2024.
//

Zoomie::Zoomie(){
    this->breedTicks = 0;
    this->moved = false;
}
Zoomie::Zoomie(World* world, int x, int y){

}
void Zoomie::breed(){
    std::cout << "ez";

};       // Whether or not to breed
void Zoomie::move(){

};        // Rules to move the critter
int Zoomie::getType(){
    return 1;
}       // Return if Swoopie or Zoomie
bool Zoomie::starve(){
    return true;

}      // Determine if organism starves

