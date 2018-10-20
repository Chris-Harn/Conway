#include "Tile.h"

#include <iostream>

#include "Game.h"

int main( int argc, char* argv[] ) {
	Game g_game;

	int count = 0; // placeholder code to prevent infinite loop until handleEvents is filled in

	g_game.init( 80, 40 );
	while( g_game.running() == true ) {
		g_game.handleEvents();
		g_game.update();
		g_game.render();
		count++;
		if( count > 10000 )  
			g_game.exit();
	}	
	g_game.clean();

	std::cout << "Program finished without issue." << std::endl;

	return 0;
}
