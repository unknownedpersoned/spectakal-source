// "weapondata.h" holds information about weapons and makes them hurt
#ifndef INCLUDE_WEAPONDATA_H
#define INCLUDE_WEAPONDATA_H

typedef enum Weapon {
	Weapon_AR     = 1,
	Weapon_PISTOL = 2,
	Weapon_BOW    = 3,
	// no weapon held
	Weapon_NONE   = 0,
	// melee weapons should have <0 value to distinguish types
	Weapon_SWORD  = -1
} Weapon;

typedef enum WeaponDetails {
	WeaponDetails_DISCHARGE = 0,
	WeaponDetails_PULLOUT   = 1,
	WeaponDetails_RANGE     = 2,
	WeaponDetails_DAMAGE    = 3,
	WeaponDetails_RELOAD	= 4,
	WeaponDetails_BSPEED	= 5,
	WeaponDetails_USES	    = 6,
	WeaponDetails_RECOIL	= 7,
	WeaponDetails_WIDTH 	= 8,
	WeaponDetails_HEIGHT    = 9
} WeaponDetails;

extern int weapondata_WeaponProperties[4][10];

// assault rifle stats/behavior
extern int weapondata_AR_DISCHARGE, 
		   weapondata_AR_PULLOUT,
		   weapondata_AR_RANGE,
		   weapondata_AR_DAMAGE,
		   weapondata_AR_RELOAD,
		   weapondata_AR_BSPEED,
		   weapondata_AR_USES,
		   weapondata_AR_RECOIL,
		   weapondata_AR_WIDTH,
		   weapondata_AR_HEIGHT;

// "deagle" behavior
extern int weapondata_PISTOL_DISCHARGE,
		   weapondata_PISTOL_PULLOUT,
		   weapondata_PISTOL_RANGE,
		   weapondata_PISTOL_DAMAGE,
		   weapondata_PISTOL_RELOAD,
		   weapondata_PISTOL_BSPEED,
		   weapondata_PISTOL_USES,
		   weapondata_PISTOL_RECOIL,
		   weapondata_PISTOL_WIDTH,
		   weapondata_PISTOL_HEIGHT;

void weapondata_InitializeSystem();

#endif
