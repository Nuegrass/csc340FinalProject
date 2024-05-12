//
// Created by amytx on 5/9/2024.
//
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"

int main(){
    World* ez =  new World();

    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution(0.0,30.0);//generate a random number from 0-30

    for (int i = 0; i < 5; ++i) {
        int xPos =distribution(generator);
        int yPos =distribution(generator);
        Zoomie* ezz= new Zoomie(ez, xPos,yPos);
        std::cout << "random xPos is " << xPos << std::endl;
        std::cout << "random yPos is " << yPos << std::endl;
        std::cout << "calling Zoomie toString " << ezz->toString() <<std::endl;
        std::cout << "ezz"<<std::endl;

        ez->setAt(xPos, yPos, ezz);
    }
    ez->Display();

}
