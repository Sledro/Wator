// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Shark 
{
private:
    sf::Texture sharkTexture;
    sf::Sprite sharkSprite;

public:
    Shark();
    sf::Sprite getSharkSprite();
};