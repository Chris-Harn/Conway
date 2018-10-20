#include <SDL2/SDL.h>
#include <iostream>

#include "Main.h"
#include "Game.h"

int main( int argc, char* argv[] ) {
	Game g_game;
	Uint32 Timer = SDL_GetTicks();

	g_game.init( 80, 40 );
	while( g_game.running() == true ) {
		g_game.handleEvents();
		g_game.update();

		if( ( SDL_GetTicks() - Timer ) > DELAY ) {
			Timer = SDL_GetTicks();
			g_game.render();
		}
	}	
	g_game.clean();

	std::cout << "Program finished without issue." << std::endl;

	return 0;
}
