#include "Zoomie.h"

//
// Created by amytx on 5/9/2024.
//

Zoomie::Zoomie(){
    this->breedTicks = 0;
    this->moved = false;
}
Zoomie::Zoomie(World* world, int x, int y){
    this->x = x;
    this->y = y;
    this->world = world;
}
void Zoomie::breed() {
    std::cout << "ez";

};       // Whether or not to breed
void Zoomie::move(){

};        // Rules to move the critter
int Zoomie::getType(){
    return 1;
}       // Return if Swoopie or Zoomie
bool Zoomie::starve(){
    return true;

}

Zoomie::~Zoomie() {//destructor

}

Zoomie::Zoomie(const Zoomie &zoom) {

}
std::string Zoomie::toString(){
    std::string tmp;
    int tmpX = this->x;
    int tmpY = this->y;
    tmp = "xPos : " + std::to_string(tmpX) + " yPos : " +std::to_string(tmpY) ;
    return tmp;
}

/*Zoomie &Zoomie::operator=(const Zoomie &zoomer) {
    return <#initializer#>;
}*/
// Determine if organism starves

