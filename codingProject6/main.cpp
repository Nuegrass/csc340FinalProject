//
// Created by amytx on 5/9/2024.
//
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"
#include "unitTest.h"

int main(){
    //unit tests
    if (testZoomieConsturctor()) {
        std::cout << "Zoomie Constructor Test Passed" << std::endl;
    } else {
        std::cout << "Zoomie Constructor Test Failed" << std::endl;
    }

    //test testZoomie_Move_Breed()
    if (testZoomie_Move_Breed()) {
        std::cout << "Zoomie Move Breed Test Passed" << std::endl;
    } else {
        std::cout << "Zoomie Move Breed Test Failed" << std::endl;
    }

    //test testSwoopieConsturctor()
    if (testSwoopieConsturctor()) {
        std::cout << "Swoopie Constructor Test Passed" << std::endl;
    } else {
        std::cout << "Swoopie Constructor Test Failed" << std::endl;
    }
    // test testSwoopie_Starve()
    if (testSwoopie_Starve()) {
        std::cout << "Swoopie Starve Test Passed" << std::endl;
    } else {
        std::cout << "Swoopie Starve Test Failed" << std::endl;
    }

    World* world =  new World();

    //generate random x and y positions
    std::random_device rd;
    std::mt19937 generator(rd()); // Seed the generator
    std::uniform_int_distribution<> distribution(0,29);//generate a random number from 0-29

    //Adding 5 Swoopies to the World
    int numOfSwoopies = 1;
    for (int i = 0; i < numOfSwoopies; ++i) {
        int xPos =distribution(generator); //generate a random x position
        int yPos =distribution(generator); //generate a random y position
        new Swoopie(world,xPos, yPos); // add a new Swoopie to random position (xPos, yPos)
    }

    //adding 100 Zoomies to the World
    int numOfZoomies = 1;
    for (int i = 0; i < numOfZoomies; ++i) {
        int xPos = distribution(generator); //generate a random x position
        int yPos = distribution(generator); //generate a random y position
        new Zoomie(world, xPos, yPos);// add a new Zoomie to (xPos, yPos)
    }

    //display the intial world and prompt the user to press Enter to continue
    world->Display(); //
    std::cout << "Press Enter to continue..." << std::endl ;
    char userInput;
    std::cin.get(userInput); // Get the user input

    // Perform simulation steps while the user presses Enter
    while (userInput == '\n') {
        world->SimulateOneStep();// Perform simulation step
        world->Display(); // Display the simulation
        std::cout << "Press Enter to continue..." << std::endl;
        // Prompt the user to press Enter to continue
        std::cin.get(userInput);
    }
    return 0;
}
