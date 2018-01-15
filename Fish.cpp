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
	arr.clear();
	//cout << "FISH-> y:" << x << " x:" << y << endl;

	if (FISH[x-1][y]==-1){ //If North
		//cout << "FISH LOCATED NORTH. y:" << x-1 << " x:" << y-1 << endl;
		arr.push_back('N');
	}
	if (FISH[x+1][y]==-1){ //If East
		//cout << "FISH LOCATED SOUTH. y:" << x+1 << " x:" << y-1 << endl;
		arr.push_back('S');
	}
	if (FISH[x][y+1]==-1){ //If South
		//cout << "FISH LOCATED EAST. y:"  << x << " x:" << y+1 << endl;
		arr.push_back('E');
	}
	if (FISH[x][y-1]==-1){ //If West
		//cout << "FISH LOCATED WEST. y:"  << x << " x:" << y-1 << endl;
		arr.push_back('W');
	}

	//cout << "-------------------------------------" << endl;

	return arr;

}


void Fish::moveFish(std::vector< char > possibleLocations, int x, int y){

	srand (time (0)); // makes rand more random
	int rand=std::rand() % possibleLocations.size(); // Random number between 1- number of possible directions stored in vector.

	char loc = possibleLocations[rand];

	if(loc=='N'){
		cout << "Move N  " <<endl;
	    FISH[x][y]=-1;
		FISH[x-1][y]=1; //Set fish north of old location	 -1 x =north
		FISHMOVE[x-1][y]=1;
	}
	
	else if(loc=='E'){
		cout << "Move E  "<<endl;
	    FISH[x][y]=-1;
		FISH[x][y+1]=1; //Set fish south of old location
		FISHMOVE[x][y+1]=1;
	}
	
	else if(loc=='S'){
		cout << "Move S  "<<endl;
	     FISH[x][y]=-1;
		FISH[x+1][y]=1; //Set fish east of old location
		FISHMOVE[x+1][y]=1;
	}
	else if(loc=='W'){
		cout << "Move W  "<<endl;
	    FISH[x][y]=-1;
		FISH[x][y-1]=1; //Set fish west of old location
		FISHMOVE[x][y-1]=1;
	}

}