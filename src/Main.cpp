#include "Main.h"
#include "Game.h"
#include "Timer.h"

int main() {
	Timer Clock;
	Clock.init( DELAY_RENDERER, DELAY_UPDATE_BOARD );

	if( TheGame::instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT ) ) {
		return 1;
	}

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
