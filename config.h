// Authors: Daniel Hayden & Frank Rooney
// Date: 17/11/17
// Description: This file contains all the shared configuration variable that 
// can be modified. This file is included in every class. 

static const int GRID_COLS = 32; //Number of grid columns
static const int GRID_ROWS = 14; //Number of grid rows

int nSharks = 20;   //Number of sharks to spawn at launch
int nFish = 30;     //Number of fish to spawn at launch
int sBreed = 10;    //Number of time units that pass before a shark can reproduce
int fBreed = 10;    //Number of time units that pass before a fish can reproduce
int starve = 10;    //Period of time units a shark can go without food before dying
int threads = 1;    //Number threads this progrm can create/use
float chronon = 1.0f;    //Number of seconds per chronon (chronon = unit of time in this ecosystem)
