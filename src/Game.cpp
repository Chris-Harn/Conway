#include "Game.h"

#include "Board.h"
#include "Input.h"

#include <cstddef>
Game* Game::s_pInstance = 0;

Game::Game() : m_bRunning( true ), m_pboard( 0 ), m_bPaused( true ) {

}

Game::~Game() {

}

void Game::init( int boardWidth, int boardHeight ) {
	m_pboard = new Board( boardWidth, boardHeight );
}

void Game::render() {
	m_pboard->clearScreen();
	m_pboard->drawBoard();
//	m_pboard->drawNumbers();
}

void Game::update() {
//	m_pboard->randomizeBoard();
	m_pboard->countNeighbors();
	m_pboard->updateBoard();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}

void Game::clean() {
	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
}

void Game::changePause() { 
	if( m_bPaused == true ) {
		m_bPaused = false;
	} else {
		m_bPaused = true;
	}
}

bool Game::gamePaused() {
	return m_bPaused;
}

