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
 *  Purpose: Flips buffer.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/


void Game::render() {
	TheBoard::instance()->drawScreen();
}


void Game::update() {
	TheBoard::instance()->countNeighbors();
	TheBoard::instance()->updateBoard();
}


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


void Game::clean() {
	TheBoard::instance()->clean();
	TheInputHandler::instance()->clean();
	TheGraphics::instance()->clean();
}


void Game::pauseBoard() {
	m_bpaused = true;
}


void Game::unpauseBoard() {
	m_bpaused = false;
}



bool Game::gamePaused() {
	return m_bpaused;
}
