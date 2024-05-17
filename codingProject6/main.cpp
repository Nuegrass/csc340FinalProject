//
// Created by amytx on 5/9/2024.
// assist by GitHub Copilot
#include "World.h"
#include "Organism.h"
#include "Zoomie.h"
#include "unitTest.h"

int main(){
    //unit tests
    callAllUnitTests();

    World* world =  new World();
    //generate random x and y positions
    std::random_device rd;
    std::mt19937 generator(rd()); // Seed the generator
    std::uniform_int_distribution<> distribution(0,29);// to generate a random number from 0-29

    //Adding 5 Swoopies to the World
    int numOfSwoopies = 15;
    for (int i = 0; i < numOfSwoopies; ++i) {
        int xPos =distribution(generator); //generate a random x position
        int yPos =distribution(generator); //generate a random y position
        new Swoopie(world,xPos, yPos); // add a new Swoopie to random position within the world
    }

    //adding 100 Zoomies to the World
    int numOfZoomies = 100;

    for (int i = 0; i < numOfZoomies; ++i) {
        int xPos = distribution(generator); //generate a random x position
        int yPos = distribution(generator); //generate a random y position
        //if the position is already occupied by swoopie
        // make a battle between Zoomie and Swoopie
        if(world->getAt(xPos, yPos) != nullptr){
          int randNum = distribution(generator) % 2; //generate a random number from 0-1
          if(randNum == 0){ // 0 is zoomie win, 1 is swoopie win
              new Zoomie(world, xPos, yPos);// add a new Zoomie to (xPos, yPos)
          }
        }
        else{ //if the cell is empty add a new Zoomie to the cell
            new Zoomie(world, xPos, yPos);// put the Zoomie to (xPos, yPos)
        }
    }

    //display the intial world and prompt the user to press Enter to continue
    world->Display();
    std::cout << "Press Enter to continue..." << std::endl ;
    char userInput;
    std::cin.get(userInput); // Get the user input

    int numOfSimulations = 0; //number of simulations

    // Perform simulation steps while the user presses Enter
    while (userInput == '\n') {
        numOfSimulations++;
        std::cout << "Number of Simulations: " << numOfSimulations << std::endl;
        world->SimulateOneStep();// Perform simulation step
        world->Display(); // Display the simulation
        std::cout << "Press Enter to continue..." << std::endl;
        // Prompt the user to press Enter to continue
        std::cin.get(userInput);

    }
    return 0;
}
