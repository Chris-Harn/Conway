#include "Graphics.h"

#include <SDL2/SDL.h>

Graphics::Graphics() {
	m_prenderer = NULL;
	m_pwindow = NULL;
}

Graphics::~Graphics() {

}

bool Graphics::init( const int screenWidth, const int screenHeight ) {
	if( SDL_Init( SDL_INIT_VIDEO ) >= 0 ) {
		m_pwindow = SDL_CreateWindow( "Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

		if( m_pwindow != 0 ) {
			m_prenderer = SDL_CreateRenderer( m_pwindow, -1, 0 );
		}
	} else {
		return 1;
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
