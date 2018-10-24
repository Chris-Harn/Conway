#ifndef __GRAPHICS__
#define __GRAPHICS__

class SDL_Renderer;
class SDL_Window;

class Graphics {
public:
	Graphics();
	~Graphics();
	bool init( int screenWidth, int screenHeight );
	void clean();

	void drawBoard();
private:
	SDL_Renderer *m_prenderer;
	SDL_Window *m_pwindow;
};

#endif
