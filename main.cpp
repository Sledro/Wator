// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file starts the program and contorls the program
// it creates the Grid Fish and Shark Objects and preforms logic on them
// to place them in their correct position on each new chronon
#include <iostream>
#include "Grid.h"
#include "Fish.h"
#include "Shark.h"
#include <SFML/Graphics.hpp>
#include "Config.h"

using namespace std;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1360, 560), "Wator Ecosystem Simulator");//1285, 560

    Grid grid;      //Create a single grid sprite object
    Fish fish;      //Create a single fish sprite object
    Shark shark;    //Create a single shark sprite object

    sf::Sprite GRID[GRID_ROWS][GRID_COLS];
    srand (time (0));  //Makes rand() more random

    //Fill fish array wih -1's
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           fish.FISH[i][j]=-1;
        }
    }

    //Enter fish notated by 1's at random locations into the FISH array
    for (int i=0; i<nFish; i++){
        fish.FISH[rand() % GRID_ROWS + 1 ][rand() % GRID_COLS + 1 ]=1;
    }


    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
          std::cout << fish.FISH[i][j];
        }
        std::cout << endl;
    }

    //Fill Shark array wih -1's
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
           shark.SHARKS[i][j]=-1;
        }
    }

    //Enter shark notated by 1's at random locations into the SHARKS array
    for (int i=0; i<nSharks; i++){
        shark.SHARKS[rand() % GRID_ROWS + 1 ][rand() % GRID_COLS + 1 ]=1;
    }


    //Fill GRID array with grid sprites
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
            if(fish.FISH[i][j]!=1){
                GRID[i][j]=grid.getGridSprite();
            }
            if (shark.SHARKS[i][j]==1){
                GRID[i][j]=shark.getSharkSprite();      
            }
            if (fish.FISH[i][j]==1){
                GRID[i][j]=fish.getFishSprite();
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

            for (int i=0; i<GRID_ROWS; i++){
                for (int j=0; j<GRID_COLS; j++) {
                    //Set position of sprite to make grid and darw
                    GRID[i][j].setPosition(j * 40,i * 40);
                    window.draw(GRID[i][j]);

                    if(fish.FISH[i][j]!=-1)
                        fish.FISH[i][j]=timeCounter;

                     fish.findMoveLocation(i,j);

                }
                

            }


                //Echo out Sharks array
            for (int i=0; i<GRID_ROWS; i++){
                for (int j=0; j<GRID_COLS; j++) {
                   std::cout << "(" << fish.FISH[i][j] << ") ";
                }
                std::cout << endl;
            }  

            timeCounter++;
            //std::cout << timeCounter << endl;
            window.display();

            //Reset the timeSinceLastUpdate to 0 
            timeSinceLastUpdate = sf::Time::Zero;
        }
    }
}