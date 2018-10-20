#include <SDL2/SDL.h>
#include <iostream>

#include "Main.h"
#include "Game.h"

int main( int argc, char* argv[] ) {
	Game g_game;
	Uint32 Timer = SDL_GetTicks();

	g_game.init( GAME_WIDTH, GAME_HEIGHT );
	while( g_game.running() == true ) {
		g_game.handleEvents();

		if( ( SDL_GetTicks() - Timer ) > DELAY ) {
			Timer = SDL_GetTicks();
			g_game.update();
			g_game.render();
		}
	}	
	g_game.clean();

	std::cout << "Program finished without issue." << std::endl;

	return 0;
}
