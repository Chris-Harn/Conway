#include "Game.h"


#include "Board.h"
#include "Input.h"
#include "Graphics.h"

// for testing
#include <iostream>

Game* Game::s_pInstance = 0;

Game::Game() : m_brunning( true ), m_bpaused( true ) {
	
}

Game::~Game() {

}

bool Game::init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight ) {
	TheBoard::instance()->init( boardWidth, boardHeight );
	TheGraphics::instance()->init( screenWidth, screenHeight );
	TheInputHandler::Instance()->init();

	return true;
}

void Game::render() {
	TheBoard::instance()->clearScreen();
	TheBoard::instance()->drawBoard();
	// TheBoard::instance()->drawNumbers(); // shows neighbor cell counts
}

void Game::update() {
	TheBoard::instance()->countNeighbors();
	TheBoard::instance()->updateBoard();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
	if( TheInputHandler::Instance()->onKeyDown( SDL_SCANCODE_SPACE ) ) {
		TheGame::Instance()->unpauseBoard();
	}

	if( TheInputHandler::Instance()->onKeyDown( SDL_SCANCODE_RETURN ) ) {
		TheGame::Instance()->pauseBoard();
	}
}

void Game::clean() {
	TheBoard::instance()->clean();
	TheGraphics::instance()->clean();
	TheInputHandler::Instance()->clean();

	/*
	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
	*/
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
