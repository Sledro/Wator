// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Fish.h"

Fish::Fish(){

    if (!fishTexture.loadFromFile("images/fish.png"))
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
	
	// Find and returns direction to fish
void Fish::findMoveLocation(int x, int y)
{


	//srand (time (0)); // makes rand more random
	//int rand= rand() % 4; // Random number between 1-4

	/*char N;
	char S;
	char E;
	char W;*/

	if (FISH[x-1][y]==1){ //If North
		cout << "FISH LOCATED NORTH";
	}
	if (FISH[x+1][y]==1){ //If North
		cout << "FISH LOCATED SOUTH";
	}
	if (FISH[x][y+1]==1){ //If North
		cout << "FISH LOCATED EAST";
	}
	if (FISH[x][y-1]==1){ //If North
		cout << "FISH LOCATED WEST";
	}

}