/*
 * Swarm.h
 *
 *  Created on: Mar 13, 2018
 *      Author: jordanboggs
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace jab {

class Swarm {
public:
	const static int NPARTICLES = 500;

private:
	Particle *pParticles;

public:
	float x;
	float y;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	Particle * const getParticles() { return pParticles; }
	void reset();
};

} /* namespace jab */

#endif /* SWARM_H_ */
