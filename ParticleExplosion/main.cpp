#include "Screen.h"
#include <math.h>
#include "Swarm.h"
#include <time.h>

using namespace std;
using namespace ParticleExplosion;

int main(int argc, char* argv[])
{

	srand(time(NULL)); // random number seed

	Screen screen;

	// Initializing SDL 
	if(!screen.init()){
		cout << "Error Initializing SDL." << endl;
	}

	Swarm swarm;

	// Main loop
	while (true){
		// Update Particles
		// Draw particles

		int elapsed = SDL_GetTicks();
		
		// screen.clear();
		swarm.update(elapsed);

		// gradually changing color values
		// we can also use cos in place of sin as they both have same range (-1, 1) and same domain 
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.00002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++){
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT/2; 

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the screen
		screen.update();

		//Checking for messages/events
		if (!screen.processEvents()){
			break;
		}
	}

	// The end part
	screen.close();
	
	return 0;
}