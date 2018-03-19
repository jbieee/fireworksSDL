/*
 * Particle.h
 *
 *  Created on: Mar 13, 2018
 *      Author: jordanboggs
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>
#include <SDL.h>

namespace jab {

class Particle {
public:
	const static int PARTICLERADIUS = 3;

private:
	double speed;
	double direction;


private:
	void init();

public:
	double x;
	double y;
	Uint8 red;
	Uint8 green;
	Uint8 blue;

public:
	Particle();
	void update(int interval);
};

} /* namespace jab */

#endif /* PARTICLE_H_ */
