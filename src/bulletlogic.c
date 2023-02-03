// "bulletlogic.c" for bullets and guns and AMERICA
#include "../bulletlogic.h"

#include <math.h>
#include "libs/raylib.h"
#include "../weapons.h"
#include "../weapondata.h"

const int MAX_BULLETS = 1000;
static Bullet ActiveBullets[MAX_BULLETS];
static Bullet *cb;
int BulletCount;

void ShootBullet(Weapon type) {
	ActiveBullets[BulletCount] = (Bullet){
		_WeaponRect.x, 
		_WeaponRect.y,
		WeaponRotationToMouseAngle,
		type, 0, 
		floor(WeaponProperties[type][BSPEED] * cos(WeaponRotationToMouseAngle)), 
		floor(WeaponProperties[type][BSPEED] * sin(WeaponRotationToMouseAngle))
	};
	BulletCount++;
}

void UpdateAndDrawBullets() {
	for (int i = 0;;) {
		if (i == BulletCount) return;
		if (ActiveBullets[i].T) {
			cb = &ActiveBullets[i];
			cb->X += cb->MX;
			cb->Y += cb->MY;
			cb->L++;
			if (
				(int)sqrt((cb->MX * cb->L)*(cb->MX * cb->L) + (cb->MY * cb->L)*(cb->MY * cb->L)) 
					>
				WeaponProperties[cb->T][RANGE]
			) {
				BulletCount--;
				ActiveBullets[i] = ActiveBullets[BulletCount];
				ActiveBullets[BulletCount].T = -1;
				continue;
			}
			DrawRectangle
			(
				cb->X, 
				cb->Y, 
				4, 
				4, 
				(Color){218, 218, 65, 255}
			);
		}
		i++;
	}
}
