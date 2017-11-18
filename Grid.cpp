// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Grid.h"

Grid::Grid(){

    if (!gridTexture.loadFromFile("images/grid.png"))
    {
       std::cout<<"Error loading grid.png";
    }
    
    gridSprite.setTexture(gridTexture);
    gridSprite.setScale(1, 1);
}

sf::Sprite Grid::getGridSprite()
{
    return gridSprite;   
}