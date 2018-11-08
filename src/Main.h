#ifndef __MAIN__
#define __MAIN__

// SDL Settings
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int CELL_SIZE_X = 4;
const int CELL_SIZE_Y = 4;

// Gameplay Loop
const double FPS = 20; // per sec
const double UPDATE_SIM = 10; // per sec
const double DELAY_RENDERER = 1000 / FPS;
const double DELAY_UPDATE_BOARD = 1000 / UPDATE_SIM;

// Board Settings 
const int GAME_WIDTH = SCREEN_WIDTH / CELL_SIZE_X;
const int GAME_HEIGHT = SCREEN_HEIGHT / CELL_SIZE_Y;

#endif
