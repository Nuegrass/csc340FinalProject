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
//        Zoomie* ezz= new Zoomie(ez, xPos,yPos);
        Swoopie* pzz = new Swoopie(ez,xPos, yPos);
        std::cout << "random xPos is " << xPos << std::endl;
        std::cout << "random yPos is " << yPos << std::endl;
        std::cout << "calling Zoomie toString " << pzz->toString() <<std::endl;
        std::cout << "ezz"<<std::endl;
/*
        ez->setAt(xPos, yPos, ezz);
        ez->setAt(xPos+1, yPos+2, pzz);*/

    }

    for (int i = 0; i < 100; ++i) {
        int xPos =distribution(generator);
        int yPos =distribution(generator);
        Zoomie* ezz= new Zoomie(ez, xPos,yPos);
//        Swoopie* pzz = new Swoopie(ez,xPos, yPos);
        std::cout << "random xPos is " << xPos << std::endl;
        std::cout << "random yPos is " << yPos << std::endl;
        std::cout << "calling Zoomie toString " << ezz->toString() <<std::endl;
        std::cout << "ezz"<<std::endl;
/*
        ez->setAt(xPos, yPos, ezz);
        ez->setAt(xPos+1, yPos+2, pzz);*/

    }

    ez->Display();
    // Loop indefinitely
    ez->SimulateOneStep();
    ez->Display();

    return 0;
}
