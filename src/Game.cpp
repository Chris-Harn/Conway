#include "Game.h"

#include "Board.h"
#include "Input.h"
#include "Graphics.h"

Game* Game::s_pinstance = 0;


/**************************************************
 *  Game::Game()
 *  Purpose: Start sim paused.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Game::Game() : m_brunning( true ), m_bpaused( true ) {
	
}


/**************************************************
 *  Game::init 
 *  Purpose: First call that creates several sub-
 *  	systems: Board, Graphics, and then creates
 *  	SDL context.
 *  Input: boardWidth and boardHeight in tiles.
 *  	screenWidth and screenHeigth in pixels.
 *  Return: returns true if it fails, false if 
 *  	it succeeds.
 *
 *************************************************/

bool Game::init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight ) {
	TheBoard::instance()->init( boardWidth, boardHeight );

	// initiate graphics
	if( TheGraphics::instance()->init( screenWidth, screenHeight ) ) {
		return true;
	}

	// do this to draw board for first time after initating graphics
	TheBoard::instance()->clearScreen();
	TheBoard::instance()->drawEntireScreen();
	TheBoard::instance()->drawScreen();
	
	TheInputHandler::instance()->init();

	return false;
}


/**************************************************
 *  Game::render
 *  Purpose: Flips buffer that we've been drawing 
 *  too.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::render() {
	TheBoard::instance()->drawScreen();
}


/**************************************************
 *  Game::update
 *  Purpose: Itterates through every tile, counts
 *  the neighboring living tiles, figures out if the
 *  tile should be changed, adds that tile to a list
 *  to be changed later, and then calls updateBoard
 *  where it changes only the designated tiles in 
 *  one pass.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::update() {
	TheBoard::instance()->countNeighbors();
	TheBoard::instance()->updateBoard();
}


/**************************************************
 *  Game::handleEvents
 *  Purpose: Checks events for keyboard/mouse input
 *  and commands a TheBoard, TheGraphics, or 
 *  TheGame how to act in response.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::handleEvents() {
	TheInputHandler::instance()->update();
	if( TheInputHandler::instance()->onKeyDown( SDL_SCANCODE_SPACE ) ) {
		TheGame::instance()->unpauseBoard();
	}

	if( TheInputHandler::instance()->onKeyDown( SDL_SCANCODE_RETURN ) ) {
		TheGame::instance()->pauseBoard();
	}

	if( TheInputHandler::instance()->onKeyDown( SDL_SCANCODE_ESCAPE ) ) {
		m_brunning = false;
	}
}


/**************************************************
 *  Game::clean
 *  Purpose: Calls clean for all singletons.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::clean() {
	TheBoard::instance()->clean();
	TheInputHandler::instance()->clean();
	TheGraphics::instance()->clean();
}


/**************************************************
 *  Game::pauseBoard
 *  Purpose: Makes the simulation pause updating. 
 *  Made seperate from unpauseBoard to prevent sim
 *  from being started/stopped multiple times with
 *  one key press.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::pauseBoard() {
	m_bpaused = true;
}


/**************************************************
 *  Game::unpauseBoard
 *  Purpose: Makes the simulation unpause updating.
 *  Made sperate from pauseBoard to prevent sim
 *  from being started/stopped multipl times with
 *  one key press.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Game::unpauseBoard() {
	m_bpaused = false;
}


/**************************************************
 *  Game::gamePause
 *  Purpose: Check if sim is paused/unpaused.
 *  Input: None.
 *  Return: bool
 *
 *************************************************/

bool Game::gamePaused() {
	return m_bpaused;
}
