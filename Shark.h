// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"

using namespace std;

class Shark 
{
private:
    sf::Texture sharkTexture;
    sf::Sprite sharkSprite;

public:
    Shark();
    sf::Sprite getSharkSprite();
    int SHARKS[GRID_ROWS][GRID_COLS];      //Location/Age of Sharks
    int SHARKSMOVE[GRID_ROWS][GRID_COLS];
    void putSharksOnMapAtRandomLocations();
    std::vector< char > findMoveLocation(int x, int y);
    void moveShark(std::vector< char > possibleLocations, int x, int y, int timeCounter);
};