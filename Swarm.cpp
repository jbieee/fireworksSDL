/*
 * Swarm.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jordanboggs
 */

#include "Swarm.h"

namespace jab {

Swarm::Swarm() : lastTime(0) {
	x = ((0.9 * rand()) / RAND_MAX) - 0.5;
	y = ((0.9 * rand()) / RAND_MAX) - 0.5;
	pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete[] pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		pParticles[i].update(interval);
	}
	lastTime = elapsed;
}

void Swarm::reset() {
	x = ((0.9 * rand()) / RAND_MAX) - 0.5;
	y = ((0.9 * rand()) / RAND_MAX) - 0.5;
	delete[] pParticles;
	pParticles = new Particle[NPARTICLES];
}

} /* namespace jab */
