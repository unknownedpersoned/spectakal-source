// "weapons.c" weapons management
#include "../weapons.h"

#include <stdlib.h>
#include <math.h>
#include "libs/raylib.h"
#include "../game.h"
#include "../weapondata.h"
#include "../bulletlogic.h"
#include "../player.h"
#include "../input.h"

int               weapons_DrawHeldWeapon                 = 0,
	              weapons_WeaponRotation                 = 0,
	              weapons_WeaponDischarging	             = 0,
	              weapons_WeaponAbleToDischarge          = 1,
	              weapons_WeaponLastDischarged           = 0,
                  weapons_WeaponUsesLeft[4];
float             weapons_RotationToMouseDeg;
Vector2           weapons_WeaponPositionRelativeToPlayer = { 30, -20 };
Weapon            weapons_HeldWeapon                     = Weapon_NONE;
Rectangle         weapons_DisplayRect;

static Rectangle  _AnimationRect                         = {0,0,0,0};
static int        _FrameCounter                          = 0;
static float      _IncReload                             = 0, 
                  _IncDischarge                          = 0;

// int Reload: 0 is discharge, 1 is reload
static void _UpdateAndDrawWeaponReloadAnimation() {
	if (_FrameCounter > weapondata_WeaponProperties[weapons_HeldWeapon][WeaponDetails_RELOAD]) {
		_AnimationRect.width = 0.0f; return;
	}
	_AnimationRect.x = weapons_DisplayRect.x;
	_AnimationRect.y = weapons_DisplayRect.y;
	_AnimationRect.width += _IncReload;
	if (_AnimationRect.width > weapons_DisplayRect.width) { 
		_AnimationRect.width = 0.0f; return;
	}
	DrawRectanglePro(_AnimationRect, (Vector2){0,0}, weapons_WeaponRotation, GREEN);
}

void weapons_SwapHeld(Weapon weapon) {
	if (weapon == Weapon_NONE) {
		weapons_HeldWeapon = Weapon_NONE;
		weapons_DrawHeldWeapon = 0;
		return;
	}
	weapons_HeldWeapon = weapon;
	weapons_DrawHeldWeapon = 1;
	weapons_DisplayRect.width = weapondata_WeaponProperties[weapon][WeaponDetails_WIDTH];
	weapons_DisplayRect.height = weapondata_WeaponProperties[weapon][WeaponDetails_HEIGHT];
	_IncReload = weapons_DisplayRect.width / weapondata_WeaponProperties[weapon][WeaponDetails_RELOAD];
	_IncDischarge = weapons_DisplayRect.width / weapondata_WeaponProperties[weapon][WeaponDetails_DISCHARGE];
	_AnimationRect.height = weapons_DisplayRect.height;
}

void weapons_UpdateWeaponRotation() {
	if (weapons_HeldWeapon == Weapon_NONE) return;
	// (180 / PI) * atan2(_WeaponRect.y - MY, _WeaponRect.x - MX)
	weapons_DisplayRect.x = player_PlayerPosition.x + weapons_WeaponPositionRelativeToPlayer.x;
	weapons_DisplayRect.y = player_PlayerPosition.y + weapons_WeaponPositionRelativeToPlayer.y;
	weapons_RotationToMouseDeg = atan2(input_MY - weapons_DisplayRect.y, input_MX - weapons_DisplayRect.x);
    weapons_WeaponRotation = (180 / PI) * weapons_RotationToMouseDeg;	
}

void weapons_DrawWeapon() {
 	if (!weapons_DrawHeldWeapon) return;
	DrawRectanglePro(weapons_DisplayRect, (Vector2){0,0}, weapons_WeaponRotation, BLUE);
	if (!weapons_WeaponUsesLeft[weapons_HeldWeapon]) 
		_UpdateAndDrawWeaponReloadAnimation();
}

void weapons_UpdateWeaponInput() {
	if (input_MD) {
		weapons_WeaponDischarging = 1;
	} else {
		weapons_WeaponDischarging = 0;
	}
}



void weapons_UpdateWeaponLogic() {
	// Gun
	if (weapons_HeldWeapon > 0) {
		if (!weapons_WeaponAbleToDischarge) {
			_FrameCounter++;
			if (_FrameCounter - weapons_WeaponLastDischarged > weapondata_WeaponProperties[weapons_HeldWeapon][WeaponDetails_DISCHARGE]) {
				_FrameCounter = 0;
				weapons_WeaponAbleToDischarge = 1;
			}
		} else if (weapons_WeaponDischarging && weapons_WeaponUsesLeft[weapons_HeldWeapon]) {
			bulletlogic_ShootBullet(weapons_HeldWeapon);
			weapons_WeaponAbleToDischarge = 0;
			weapons_WeaponLastDischarged = _FrameCounter = Global_FrameCount;
			weapons_WeaponUsesLeft[weapons_HeldWeapon]--;
		} else if (!weapons_WeaponUsesLeft[weapons_HeldWeapon]) {
			_FrameCounter++;
			if (_FrameCounter > weapondata_WeaponProperties[weapons_HeldWeapon][WeaponDetails_RELOAD]) {
				_FrameCounter = 0;
				weapons_WeaponUsesLeft[weapons_HeldWeapon] = 20;
				weapons_WeaponAbleToDischarge = 1;
			}
		}
	}
}


void weapons_UpdateAll() {
 	weapons_UpdateWeaponRotation();
	weapons_UpdateWeaponInput();
	weapons_UpdateWeaponLogic();
}
