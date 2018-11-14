#include "Main.h"

#include "Game.h"
#include "Timer.h"
#include "Message.h"
#include "TestSuite.h"

int main() {
	TheTestSuite::instance()->run();
	TheTestSuite::instance()->results();

	if( TheGame::instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT ) ) {
		errorMessage( "The Game failed to initialize. Exiting Program." );
		return 1;
	}

	Timer Clock;
	Clock.init( DELAY_RENDERER, DELAY_UPDATE_BOARD );

	TheGame::instance()->redrawBoard();

	while( TheGame::instance()->running() ) {
		TheGame::instance()->handleEvents();

		if( Clock.timeForRender() ) {
			if( !TheGame::instance()->gamePaused() && Clock.timeForUpdatingBoard() ) {
				TheGame::instance()->update();
			}

			TheGame::instance()->render();
		}
	}	

	TheGame::instance()->clean();

	return 0;
}
