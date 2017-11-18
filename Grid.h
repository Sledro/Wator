// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Grid 
{
private:

    sf::Texture gridTexture;
    sf::Sprite gridSprite;

public:
    Grid();
    sf::Sprite getGridSprite();
};