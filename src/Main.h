#ifndef __MAIN__
#define __MAIN__

/**************************************************
 *  CS-11 
 *  Purpose: Simulate Conway's Game of Life 
 *
 *  Author: Christopher Harn
 *  Version: 1.0 11/09/2018*
 *
 *************************************************/

// SDL Settings
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const int CELL_SIZE_X = 1;
const int CELL_SIZE_Y = 1;

// Gameplay Loop
const double FPS = 60; // per sec
const double UPDATE_SIM = 50; // per sec
const double DELAY_RENDERER = 1000 / FPS;
const double DELAY_UPDATE_BOARD = 1000 / UPDATE_SIM;

// Board Settings 
const int GAME_WIDTH = SCREEN_WIDTH / CELL_SIZE_X;
const int GAME_HEIGHT = SCREEN_HEIGHT / CELL_SIZE_Y;
const int REPRODUCE_NUMBER = 3;
const int OVERPOPULATION_NUMBER = 3;
const int ISOLATION_NUMBER = 2;

#endif
