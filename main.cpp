// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file starts the program and contorls the program
// it creates the Grid Fish and Shark Objects and preforms logic on them
// to place them in their correct position on each new chronon

#include "Grid.h"
#include "Fish.h"
#include "Shark.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

static const int GRID_COLS = 32; //Number of grid columns
static const int GRID_ROWS = 14; //Number of grid rows

int nSharks = 10;   //Number of sharks to spawn at launch
int nFish = 25;     //Number of fish to spawn at launch
int sBreed = 10;    //Number of time units that pass before a shark can reproduce
int fBreed = 10;    //Number of time units that pass before a fish can reproduce
int starve = 10;    //Period of time units a shark can go without food before dying
int threads = 1;    //Number threads this progrm can create/use
float chronon = 1.0f;    //Number of seconds per chronon (chronon = unit of time in this ecosystem)
int FISH[GRID_COLS][GRID_ROWS];   //Location/Age of Fish : -1 = No Fish otherwise number = age
int SHARKS[GRID_COLS][GRID_ROWS];      //Location/Age of Sharks

int main()
{

    sf::RenderWindow window(sf::VideoMode(1285, 560), "Wator Ecosystem Simulator");

    Grid grid;      //Create a single grid sprite object
    Fish fish;      //Create a single fish sprite object
    Shark shark;    //Create a single shark sprite object

    sf::Sprite GRID[GRID_COLS][GRID_ROWS];
    srand (time (0));  //Makes rand() more random

    //Fill fish array wih -1's
    for (int i=0; i<GRID_COLS; i++){
        for (int j=0; j<GRID_ROWS; j++) {
           FISH[i][j]=-1;
        }
    }

    //Enter fish notated by 1's at random locations into the FISH array
    for (int i=0; i<nFish; i++){
        FISH[rand() % GRID_COLS + 1 ][rand() % GRID_ROWS + 1 ]=1;
    }

     //Echo out fish 
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
          std::cout << FISH[i][j];
        }
        std::cout << endl;
    }

    //Fill Shark array wih -1's
    for (int i=0; i<GRID_COLS; i++){
        for (int j=0; j<GRID_ROWS; j++) {
           SHARKS[i][j]=-1;
        }
    }

    //Enter shark notated by 1's at random locations into the FISH array
    for (int i=0; i<nSharks; i++){
        SHARKS[rand() % GRID_COLS + 1 ][rand() % GRID_ROWS + 1 ]=1;
    }


    //Fill GRID array with grid sprites
    for (int i=0; i<GRID_COLS; i++){
        for (int j=0; j<GRID_ROWS; j++) {
            GRID[i][j]=grid.getGridSprite();
            //put a fish sprite
            if(FISH[i][j]==1){
                GRID[i][j]=fish.getFishSprite();
            }
            if(SHARKS[i][j]==1){
                GRID[i][j]=shark.getSharkSprite();
            }            
        }
    }

    //Do math to set FPS
    sf::Time timePerFrame = sf::seconds(1.0f / chronon);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    //The clock object keeps the time.
    sf::Clock clock;
    clock.restart();

    int timeCounter=0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Get the time since last update and restart the clock
        timeSinceLastUpdate += clock.restart();


        //Update every every chronon
        //Only update when on new chronon
        if (timeSinceLastUpdate > timePerFrame)
        {
            window.clear();
            for (int i=0; i<GRID_COLS; i++){
                for (int j=0; j<GRID_ROWS; j++) {
                    //Set position of sprite to make grid and darw
                    GRID[i][j].setPosition(i * 40,j * 40);
                    window.draw(GRID[i][j]);
                }
            }

            timeCounter++;
            std::cout << timeCounter << endl;
            window.display();

            //Reset the timeSinceLastUpdate to 0 
            timeSinceLastUpdate = sf::Time::Zero;
        }
    }
}