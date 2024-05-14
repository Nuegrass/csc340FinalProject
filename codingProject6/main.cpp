//
// Created by amytx on 5/9/2024.
//
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"

int main(){
    World* ez =  new World();

    //generate random x and y positions
    std::random_device rd;
    std::mt19937 generator(rd()); // Seed the generator
    std::uniform_int_distribution<> distribution(0,30);//generate a random number from 0-30

    //Adding the Zoomie and Swoopies to the World
    for (int i = 0; i < 5; ++i) {
        int xPos =distribution(generator);
        int yPos =distribution(generator);
        Zoomie* ezz= new Zoomie(ez, xPos,yPos);
        Swoopie* pzz = new Swoopie(ez,xPos+1, yPos+2);
        std::cout << "random xPos is " << xPos << std::endl;
        std::cout << "random yPos is " << yPos << std::endl;
        std::cout << "calling Zoomie toString " << ezz->toString() <<std::endl;
        std::cout << "calling Zoomie toString " << pzz->toString() <<std::endl;
        std::cout << "ezz"<<std::endl;
/*
        ez->setAt(xPos, yPos, ezz);
        ez->setAt(xPos+1, yPos+2, pzz);*/

    }
    ez->Display();

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (ez->getAt(i,j) != nullptr){
                //std::cout << "CALLING MOVE ON A ORGANISM at "<< i<<" " << j <<std::endl;
                ez->getAt(i,j)->move();
                ez->Display();
            }
        }
    }
    std::cout << "First MOVE PLS WORK LUL" << std::endl;
    ez->Display();


}
