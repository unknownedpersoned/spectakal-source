// "bulletlogic.h" for bullets and guns and AMERICA
#ifndef INCLUDE_BULLETLOGIC_H
#define INCLUDE_BULLETLOGIC_H

#include "weapondata.h"

#define bulletlogic_MAX_BULLETS 1000
extern int bulletlogic_BulletCount;

typedef struct Bullet {
	int X;
	int Y;
	float R;
	int T, L, MX, MY;
} Bullet;

void bulletlogic_ShootBullet(Weapon type);
void bulletlogic_UpdateAndDrawBullets();

#endif
