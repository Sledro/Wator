// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17
#include <SFML/Graphics.hpp>

using namespace std;
class Grid 
{
private:

    sf::Texture gridTexture;
    sf::Sprite gridSprite;

public:
    Grid();
    void start();
    int getGridCols();
    int getGridRows();
    sf::Sprite getGridSprite();
};