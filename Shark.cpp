// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Shark.h"

Shark::Shark(){

    if (!sharkTexture.loadFromFile("shark.png"))
    {
       std::cout<<"Error loading shark.png";
    }
    
    sharkSprite.setTexture(sharkTexture);
    sharkSprite.setScale(1, 1);
}

sf::Sprite Shark::getSharkSprite()
{
    return sharkSprite;   
}