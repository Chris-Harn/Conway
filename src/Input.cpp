#include "Input.h"

#include "Game.h"

Input* Input::s_pInstance = 0;

Input::Input() {
	for( int i = 0; i < 3; i++ ) {
		m_mouseButtonStates.push_back( false );
	}

	m_keystates = SDL_GetKeyboardState(0);
}

Input::~Input() {

}

void Input::update() {
	SDL_Event event;
	while( SDL_PollEvent( &event ) ) {
		switch( event.type ) {
			case SDL_QUIT:
				TheGame::Instance()->exit();
				break;
			case SDL_MOUSEMOTION:
				onMouseMove( event );
				break;
			case SDL_MOUSEBUTTONDOWN:
				onMouseButtonDown( event );
				break;
			case SDL_MOUSEBUTTONUP:
				onMouseButtonUp( event );
				break;
			case SDL_KEYDOWN:
				onKeyDown();
				break;
			case SDL_KEYUP:
				onKeyUp();
				break;
			default:
				break;
		}
	}
}

void Input::clean() {

}

void Input::onKeyDown() {
	m_keystates = SDL_GetKeyboardState(0);
}

bool Input::onKeyDown( SDL_Scancode key ) {
	if( m_keystates != 0 ) {
		if( m_keystates[key] == 1 ) {
			return true;
		} else {
			return false;	
		}
	}	
	return false;
}

void Input::onKeyUp() {
	m_keystates = SDL_GetKeyboardState(0);
}

void Input::onMouseMove( SDL_Event& event ) {

}

void Input::onMouseButtonDown( SDL_Event& event ) {
	if( event.button.button = SDL_BUTTON_LEFT ) {
		m_mouseButtonStates[LEFT] = true;
	}
}

void Input::onMouseButtonUp( SDL_Event& event ) {
	if( event.button.button = SDL_BUTTON_LEFT ) {
		m_mouseButtonStates[LEFT] = false;
	}
}
