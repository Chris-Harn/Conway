#ifndef __MAIN__
#define __MAIN__

// Gameplay Loop
const double FPS = 15;
const double DELAY_RENDERER = 1000 / FPS;
const double DELAY_UPDATE_BOARD = 1000 / 5;

// Board Settings
const int GAME_WIDTH = 80;
const int GAME_HEIGHT = 40;

// SDL Settings
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int CELL_SIZE_X = 2; // produces 960 cells across
const int CELL_SIZE_Y = 2; // produces 540 cell up and down

// Drawing Context
enum Draw {
	CONSOLE = 0,
	SDL = 1
};


#endif
