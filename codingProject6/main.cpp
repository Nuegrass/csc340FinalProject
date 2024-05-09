//
// Created by amytx on 5/9/2024.
//
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"

int main(){
    World* ez =  new World();

    std::default_random_engine generator;
    std::uniform_int_distribution<> distribution(0,30);//generate a random number from 0-30
    int xPos =distribution(generator);
    int yPos =distribution(generator);
    for (int i = 0; i < 5; ++i) {
        xPos =distribution(generator);
        yPos =distribution(generator);
        Organism* ezz= new Zoomie(ez, xPos,yPos);

        ez->setAt();
    }
}
