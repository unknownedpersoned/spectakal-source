// "particle.h" controls basic/flow particles
#ifndef INCLUDE_PARTICLE_H
#define INCLUDE_PARTICLE_H

#include "game.h"
#include "mathier.h"
#include "src/libs/raylib.h"

typedef struct Particle {
	int x, y, lifetime, type;
} Particle;

typedef enum ParticleType {
	ParticleType_Basic  = 1,
	ParticleType_Flow   = 2,
	ParticleType_Static = 3
} ParticleType;

typedef enum ParticleColor {
	ParticleColor_Sand   = 1,
	ParticleColor_Rock   = 2,
	ParticleColor_Water  = 3,
	ParticleColor_Struct = 4
} ParticleColor;

#define particle_TIME 12
#define particle_MAX_PARTICLES_ROW 225
#define particle_SIDE_LENGTH 4
extern Particle  particle_ActiveParticles[particle_MAX_PARTICLES_ROW][particle_MAX_PARTICLES_ROW];
extern int       particle_ParticleCountAll;

void particle_Initialize();

void particle_SummonParticle
(
	VectorInt2 pos,
	ParticleType type, 
	ParticleColor color
);

Particle particle_Process(int x, int y);

void particle_Draw(int x, int y, ParticleColor color);

void particle_UpdateAll();

#endif