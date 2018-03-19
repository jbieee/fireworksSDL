
#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace jab {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
	const static int SCREEN_AREA = SCREEN_WIDTH*SCREEN_HEIGHT;
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	Uint32 *m_buffer2;
public:
	Screen();
	bool init();
	bool processEvents();
	void clear();
	void close();
	void update();
	void writePixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void drawFilledCircle(int x0, int y0, int radius, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur(int intensity);
};

} /* namespace jab */

#endif /* SCREEN_H_ */
