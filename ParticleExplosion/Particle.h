#pragma once

namespace ParticleExplosion{

struct Particle
{
	double m_x;
	double m_y;

private:
	double m_speed;
	double m_direction;

private:
	void init();
	/*
	double m_xspeed;
	double m_yspeed;
	*/
public:
	Particle();
	virtual ~Particle();
	void update(int);
};
}

