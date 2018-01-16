// Authors: Daniel Hayden & Frank Rooney
// Created:15/11/17

#include "Shark.h"

Shark::Shark(){

    if (!sharkTexture.loadFromFile("images/shark.png"))
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

void Shark::putSharksOnMapAtRandomLocations(){
    int randomRow = std::rand() % GRID_ROWS + 1;
    int randomCol = std::rand() % GRID_COLS + 1;
    if(SHARKS[randomRow][randomCol]!=1){
        SHARKS[randomRow][randomCol]=1;
    }else{
        putSharksOnMapAtRandomLocations();
    }
}

// Find and returns direction to fish
// Takes in the position of the current location x,y  and the fish object from main.cpp
// Checks N,S,E, and W of the givin location and looks for a fish denoted by -1
// If no fish is found in each direction relative to x,y tha location is free so we can
// add that location to an array the holds the available move loctions (N,S,E,W)
std::vector< char > Shark::findMoveLocation(int x, int y)
{
	std::vector< char > arr;

	if (SHARKS[x-1][y]==-1 && x-1>0){ //If North
		arr.push_back('N');
	}
	if (SHARKS[x+1][y]==-1 && x+1<GRID_ROWS){ //If South
		arr.push_back('S');
	}
	if (SHARKS[x][y+1]==-1 && y+1<GRID_COLS){ //If East
		arr.push_back('E');
	}
	if (SHARKS[x][y-1]==-1 && y-1>0){ //If West
		arr.push_back('W');
	}

	return arr;
}


void Shark::moveShark(std::vector< char > possibleLocations, int x, int y, int timeCounter){

	if(possibleLocations.size()>1){
		char randomLocationFromPossible = possibleLocations[std::rand() % possibleLocations.size()];

		if(randomLocationFromPossible=='N'){
			SHARKS[x][y]=-1; 		        //Remove shark from old location 
			SHARKS[x-1][y]=timeCounter; 	//Set shark north of old location
			SHARKSMOVE[x-1][y]=1;	        //Store sharks positions that have already been moved in this cycle/chronon
		}
		else if(randomLocationFromPossible=='E'){
			SHARKS[x][y]=-1;
			SHARKS[x][y+1]=timeCounter; 
			SHARKSMOVE[x][y+1]=1;
		}
		else if(randomLocationFromPossible=='S'){
			SHARKS[x][y]=-1;
			SHARKS[x+1][y]=timeCounter; 
			SHARKSMOVE[x+1][y]=1;
		}
		else if(randomLocationFromPossible=='W'){
			SHARKS[x][y]=-1;
			SHARKS[x][y-1]=timeCounter; 
			SHARKSMOVE[x][y-1]=1;
		}
	}
}