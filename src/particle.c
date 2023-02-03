// "particle.c" controls basic/flow particles
#include "../particle.h"

#include <stdio.h>

#include "libs/raylib.h"
#include "../game.h"
#include "../gridmap.h"
#include "../mathier.h"
#include <math.h>

Particle particle_ActiveParticles[particle_MAX_PARTICLES_ROW][particle_MAX_PARTICLES_ROW];
int particle_ParticleCountAll = 0;
static Particle newp = { -1, -1, 0, 0 };


// get particle gravity based on lifetime
static int gpgrav(int lifetime) {
	return (!(lifetime - 1 % 2) ? 1 : ceil(lifetime / (ceil(particle_TIME)))) * 2;
}

void particle_Initialize() {
	for (int x = 0; x < particle_MAX_PARTICLES_ROW; x++) {
		for (int y = 0; y < particle_MAX_PARTICLES_ROW; y++) {
			particle_ActiveParticles[x][y] = (Particle)
			{
				-1, -1, 0, 0
			};
		}
	}
}

void particle_SummonParticle
(
	VectorInt2 pos,
	ParticleType type, 
	ParticleColor color
) {

}

// current particle in iteration (DrawParticles,, UpdateParticles)
static Particle *cp;
// temp vars for x and y
static int tx, ty;

// draw specific particle. x and y is position in array [x][y]
void particle_Draw(int x, int y, ParticleColor color) {
	DrawRectangle
	(
		x, 
		y, 
		particle_SIDE_LENGTH, 
		particle_SIDE_LENGTH, 
		(Color){218, 218, 65, 255}
	);
}

// process specific particle. x and y is position in array [x][y]
// returns new particle
Particle particle_Process(int x, int y) {
	cp = &particle_ActiveParticles[x][y];
	tx = x;
	ty = y;
    return newp;
}

void particle_UpdateAll(int draw) {
	if (!particle_ParticleCountAll) return;
	
}
