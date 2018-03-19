#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include <time.h>
using namespace std;
using namespace jab;

int main() {
	srand(time(NULL));

	Screen screen;
	if (!screen.init()) {
		cout << "Oopsie" << endl;
	}

	Swarm swarm;
	int interval = 0;

	while (true) {
		int elapsed = SDL_GetTicks();
		screen.clear();
		swarm.update(elapsed);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.x + swarm.x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = (particle.y + swarm.y) * Screen::SCREEN_WIDTH / 2
					+ Screen::SCREEN_HEIGHT / 2;

			screen.drawFilledCircle(x, y, Particle::PARTICLERADIUS,
					particle.red, particle.green, particle.blue);
		}

		if(elapsed - interval > 5000) {
			swarm.reset();
			interval = elapsed;
		}

		screen.update();

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();
	return 0;
}
