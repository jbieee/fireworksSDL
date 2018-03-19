/*
 * Particle.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: jordanboggs
 */

#include "Particle.h"
#include <math.h>

namespace jab {

Particle::Particle() {
	init();
}

void Particle::init() {
	x = 0;
	y = 0;

	direction = (2.0 * M_PI * rand()) / RAND_MAX;
	speed = (0.00007 * rand()) / RAND_MAX;

	red = (1 + sin(rand())) * 128;
	green = (1 + sin(rand())) * 128;
	blue = (1 + sin(rand())) * 128;
}

void Particle::update(int interval) {
	direction += interval * 0.0004;

	double xspeed = speed * cos(direction);
	double yspeed = speed * sin(direction);

	x += xspeed * interval;
	y += yspeed * interval;
}

} /* namespace jab */
