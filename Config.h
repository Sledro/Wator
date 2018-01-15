// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file contains all the shared configuration variable that 
// can be modified. This file is included in every class. 

#ifndef CONFIG_H
#define CONFIG_H

#define GRID_COLS 34 //Number of grid columns 34

#define GRID_ROWS 14 //Number of grid rows 14

#define nSharks 4  //Number of sharks to spawn at launch
#define nFish 2     //Number of fish to spawn at launch
#define sBreed 10    //Number of time units that pass before a shark can reproduce
#define fBreed 10    //Number of time units that pass before a fish can reproduce
#define starve 10    //Period of time units a shark can go without food before dying
#define threads 1    //Number threads this progrm can create/use
#define chronon 1    //Number of seconds per chronon (chronon = unit of time in this ecosystem)

#endif