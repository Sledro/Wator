// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Fish.h"

Fish::Fish(){

    if (!fishTexture.loadFromFile("fish.png"))
    {
       std::cout<<"Error loading fish.png";
    }
    
    fishSprite.setTexture(fishTexture);
    fishSprite.setScale(1, 1);
}

sf::Sprite Fish::getFishSprite()
{
    return fishSprite;   
}