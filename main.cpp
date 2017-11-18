// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file starts the program and contorls the program
// it creates the Grid Fish and Shark Objects and preforms logic on them
// to place them in their correct position on each new chronon

#include "Grid.h"
#include "Fish.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

static const int GRID_COLS = 32; //Number of grid columns
static const int GRID_ROWS = 14; //Number of grid rows

int nSharks = 10;
int nFish = 25;
int sBreed = 10;
int fBreed = 10;
int starve = 10;
int threads = 10;

int FISH[GRID_COLS][GRID_ROWS];

int main()
{

    sf::RenderWindow window(sf::VideoMode(1285, 560), "Wator Ecosystem Simulator");

    Grid grid; //Create a single grid sprite object
    Fish fish; //Create a single fish sprite object

    sf::Sprite GRID[GRID_COLS][GRID_ROWS];
    srand (time (0));  //Makes rand() more random

    //Fill fish array wih 0's
    for (int i=0; i<GRID_COLS; i++){
        for (int j=0; j<GRID_ROWS; j++) {
            FISH[i][j]=0;
        }
    }

    //Enter fish notated by 1's at random locations into the FISH array
    for (int i=0; i<nFish; i++){
        FISH[rand() % GRID_COLS + 1 ][rand() % GRID_ROWS + 1 ]=1;
    }

    //Print the fish array to console
    for (int i=0; i<GRID_ROWS; i++){
        for (int j=0; j<GRID_COLS; j++) {
            cout << "" <<FISH[i][j];
        }
        cout << "" << endl;
    }


    //Fill GRID array with grid sprites
    for (int i=0; i<GRID_COLS; i++){
        for (int j=0; j<GRID_ROWS; j++) {
            GRID[i][j]=grid.getGridSprite();
            //put a fish sprite
            if(FISH[i][j]==1){
                GRID[i][j]=fish.getFishSprite();
            }
            
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i=0; i<GRID_COLS; i++){
            for (int j=0; j<GRID_ROWS; j++) {
                //Set position of sprite to make grid and darw
                GRID[i][j].setPosition(i * 40,j * 40);
                window.draw(GRID[i][j]);
            }
        }
     
        window.display();
    }
}