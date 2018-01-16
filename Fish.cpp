// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Fish.h"
#include <iostream>

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
// Takes in the position of the current location x,y  and the fish object from main.cpp
// Checks N,S,E, and W of the givin location and looks for a fish denoted by -1
// If no fish is found in each direction relative to x,y tha location is free so we can
// add that location to an array the holds the available move loctions (N,S,E,W)
std::vector< char > Fish::findMoveLocation(int x, int y)
{
	std::vector< char > arr;

	if (FISH[x-1][y]==-1 && x-1>0){ //If North
		arr.push_back('N');
	}
	if (FISH[x+1][y]==-1 && x+1<GRID_ROWS){ //If South
		arr.push_back('S');
	}
	if (FISH[x][y+1]==-1 && y+1<GRID_COLS){ //If East
		arr.push_back('E');
	}
	if (FISH[x][y-1]==-1 && y-1>0){ //If West
		arr.push_back('W');
	}

	return arr;
}


void Fish::moveFish(std::vector< char > possibleLocations, int x, int y, int timeCounter){

	if(possibleLocations.size()>1){
		char randomLocationFromPossible = possibleLocations[std::rand() % possibleLocations.size()];

		if(randomLocationFromPossible=='N'){
			FISH[x][y]=-1; 		//Remove fish from old location 
			FISH[x-1][y]=timeCounter; 	//Set fish north of old location
			FISHMOVE[x-1][y]=1;	//Store fish positions that have already been moved in this cycle/chronon
		}
		else if(randomLocationFromPossible=='E'){
			FISH[x][y]=-1;
			FISH[x][y+1]=timeCounter; 
			FISHMOVE[x][y+1]=1;
		}
		else if(randomLocationFromPossible=='S'){
			FISH[x][y]=-1;
			FISH[x+1][y]=timeCounter; 
			FISHMOVE[x+1][y]=1;
		}
		else if(randomLocationFromPossible=='W'){
			FISH[x][y]=-1;
			FISH[x][y-1]=timeCounter; 
			FISHMOVE[x][y-1]=1;
		}
	}
}

void Fish::removeStarvedFish(int x, int y){
	if(FISH[x][y]>starve){
		FISH[x][y]=-1;
	}
}

void Fish::putFishOnMapAtRandomLocations(){
    int randomRow = std::rand() % GRID_ROWS + 1;
    int randomCol = std::rand() % GRID_COLS + 1;
    if(FISH[randomRow][randomCol]!=1){
        FISH[randomRow][randomCol]=1;
    }else{
        putFishOnMapAtRandomLocations();
		cout << "rerand";
    }
}