#include "Game.h"


#include "Board.h"
#include "Input.h"
#include "Graphics.h"

// for testing
#include <iostream>

Game* Game::s_pinstance = 0;

Game::Game() : m_brunning( true ), m_bpaused( true ) {
	
}

Game::~Game() {

}

bool Game::init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight ) {
	TheBoard::instance()->init( boardWidth, boardHeight );
	if( TheGraphics::instance()->init( screenWidth, screenHeight ) ) {
		return false;
	}
	TheInputHandler::instance()->init();

	return true;
}

void Game::render() {
	TheBoard::instance()->clearScreen();
	TheBoard::instance()->drawBoard();
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
}

void Game::clean() {
	TheBoard::instance()->clean();
	TheGraphics::instance()->clean();
	TheInputHandler::instance()->clean();
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
