#include "Game.h"

#include "Board.h"
#include "Input.h"
#include "Graphics.h"

Game* Game::s_pinstance = 0;

Game::Game() : m_brunning( true ), m_bpaused( true ) {
	
}

bool Game::init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight ) {
	// create board with single traveler
	TheBoard::instance()->init( boardWidth, boardHeight );

	// initiate graphics
	if( TheGraphics::instance()->init( screenWidth, screenHeight ) ) {
		return true;
	}	

	TheInputHandler::instance()->init();

	// do this to draw board for first time after initating graphics
	TheBoard::instance()->clearScreen();
	TheBoard::instance()->drawEntireScreen();
	TheBoard::instance()->drawScreen();

	return false;
}

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
