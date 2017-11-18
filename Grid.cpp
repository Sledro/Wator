// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Grid.h"

Grid::Grid(){

    if (!gridTexture.loadFromFile("grid.png"))
    {
       //cout<<"Error loading grid.png";
    }
    
    gridSprite.setTexture(gridTexture);
    gridSprite.setScale(1, 1);
}

void Grid::start()
{
       
}

int Grid::getGridCols()
{
    return GRID_COLS;   
}

int Grid::getGridRows()
{
    return GRID_ROWS;   
}

sf::Sprite Grid::getGridSprite()
{
    return gridSprite;   
}