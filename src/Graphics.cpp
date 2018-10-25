#include "Graphics.h"

#include <SDL2/SDL.h>
#include <iostream>

Graphics* Graphics::s_pinstance = 0;

Graphics::Graphics() : m_prenderer( 0 ), m_pwindow( 0 ) {

}

bool Graphics::init( const int screenWidth, const int screenHeight ) {
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) >= 0 ) {
		m_pwindow = SDL_CreateWindow( "Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

		if( m_pwindow != 0 ) {
			m_prenderer = SDL_CreateRenderer( m_pwindow, -1, 0 );
		} else {
			SDL_LogError( SDL_LOG_CATEGORY_APPLICATION,
					"Initialize_display - SDL_CreateWindowAndRenderer: %s\n",
					SDL_GetError() );
			return false;

		}
	} else {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION,
				"Initialize_display - SDL_Init: %s\n",
				SDL_GetError() );
		return false;
	}

	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );
	SDL_RenderClear( m_prenderer );
	SDL_RenderPresent( m_prenderer );

	return true;
}

void Graphics::clean() {	
	SDL_DestroyWindow( m_pwindow );
	SDL_DestroyRenderer( m_prenderer );
	m_pwindow = NULL;
	m_prenderer = NULL;
	SDL_Quit();
}

void Graphics::drawBoard() {

}

void Graphics::clearScreen() {
	std::cout << "\x1B[2J\x1B[H";
}

void Graphics::nextLine() {
	std::cout << "\n";
}

void Graphics::drawX() {
	std::cout << "X";
}

void Graphics::drawEmpty() {
	std::cout << "-";
}

void Graphics::drawInt( int number ) {
	std::cout << number;
}
