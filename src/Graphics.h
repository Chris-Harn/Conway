#ifndef __GRAPHICS__
#define __GRAPHICS__

class SDL_Renderer;
class SDL_Window;

class Graphics {
public:
	bool init( const int screenWidth, const int screenHeight );
	void clean();

	// console commands
	void drawScreen();
	void clearScreen();
	void nextLine();
	void drawX();
	void drawEmpty();
	void drawInt( int number );

	// SDL commands
	void drawSDLBoard();
	void clearSLDBoard();
	void updatedSDLBoard( int x, int y );

	static Graphics* instance() {
		if( s_pinstance == 0 ) {
			s_pinstance = new Graphics();
			return s_pinstance;
		}
		return s_pinstance;
	}

private:
	Graphics();
	SDL_Renderer *m_prenderer;
	SDL_Window *m_pwindow;
	static Graphics *s_pinstance;
};

typedef Graphics TheGraphics;

#endif
