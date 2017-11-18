// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17
#include <SFML/Graphics.hpp>

using namespace std;
class Fish 
{
private:
    sf::Texture fishTexture;
    sf::Sprite fishSprite;

public:
    Fish();
    sf::Sprite getFishSprite();
};