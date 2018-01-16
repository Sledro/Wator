// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"

using namespace std;

class Fish 
{
private:
    sf::Texture fishTexture;
    sf::Sprite fishSprite;

public:
    Fish();
    int FISH[GRID_ROWS][GRID_COLS];   //Location/Age of Fish : -1 = No Fish otherwise number = age
    int FISHMOVE[GRID_ROWS][GRID_COLS];
    sf::Sprite getFishSprite();
    std::vector< char > findMoveLocation(int x, int y);
    void moveFish(std::vector< char > possibleLocations, int x, int y, int timeCounter);
    void removeStarvedFish(int x, int y);
    void putFishOnMapAtRandomLocations();
};

