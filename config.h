// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file contains all the shared configuration variable that 
// can be modified. This file is included in every class. 

static const int GRID_COLS = 34; //Number of grid columns 34
static const int GRID_ROWS = 14; //Number of grid rows 14

int nSharks = 4;   //Number of sharks to spawn at launch
int nFish = 8;     //Number of fish to spawn at launch
int sBreed = 10;    //Number of time units that pass before a shark can reproduce
int fBreed = 10;    //Number of time units that pass before a fish can reproduce
int starve = 10;    //Period of time units a shark can go without food before dying
int threads = 1;    //Number threads this progrm can create/use
float chronon = 1.0f;    //Number of seconds per chronon (chronon = unit of time in this ecosystem)
int FISH[GRID_ROWS][GRID_COLS];   //Location/Age of Fish : -1 = No Fish otherwise number = age
int SHARKS[GRID_ROWS][GRID_COLS];      //Location/Age of Sharks
int FISHMOVE[GRID_ROWS][GRID_COLS]; // hold a record of each position of weather a fish has been moved there already in the current cycle. 
int SHARKMOVES[GRID_ROWS][GRID_COLS]; 
int STARVE[GRID_ROWS][GRID_COLS]; 
