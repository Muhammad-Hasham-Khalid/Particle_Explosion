#pragma once

#include "Particle.h"

namespace ParticleExplosion
{
	class Swarm
	{
	public:
		const static int NPARTICLES = 3000;
	private:
		Particle* m_pParticles;
		int lastTime;

	public:
		Swarm();
		virtual ~Swarm();
		void update(int);

		const Particle* const getParticles() { return m_pParticles; };
	};
}

