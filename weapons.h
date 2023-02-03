// "weapons.h" weapons management
#ifndef INCLUDE_WEAPONS_H
#define INCLUDE_WEAPONS_H

#include "src/libs/raylib.h"

extern int       weapons_DrawHeldWeapon,
			     weapons_WeaponRotation,
			     weapons_WeaponDischarging,
			     weapons_WeaponAbleToDischarge,
			     weapons_WeaponLastDischarged,
                 weapons_WeaponUsesLeft[4];
extern float     weapons_RotationToMouseDeg;
extern Vector2   weapons_WeaponPositionRelativeToPlayer;
extern Rectangle weapons_DisplayRect;

// Swap out the current weapon for a new one
void weapons_SwapHeld();

// Update the rotation of the weapon to point to the cursor (MX, MY)
void weapons_UpdateWeaponRotation();

// Draw the weapon attached to the player
void weapons_DrawWeapon();

// Update input variables to discharge/reload/swap weapon, etc
void weapons_UpdateWeaponInput();

// Updates the status of a swung / discharged weapon
void weapons_UpdateWeaponLogic();

// Updates all aspects of held weapon
void weapons_UpdateAll();
 
#endif
