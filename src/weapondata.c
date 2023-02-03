// "weapondata.c" holds information about weapons
#include "../weapondata.h"

#include "../weapons.h"

// assault rifle stats/behavior
int weapondata_AR_DISCHARGE    = 10, 
	weapondata_AR_PULLOUT	    = 20,
	weapondata_AR_RANGE	    = 800,
	weapondata_AR_DAMAGE	    = 5,
	weapondata_AR_RELOAD		= 180,
	weapondata_AR_BSPEED	    = 17,
	weapondata_AR_USES			= 20,
	weapondata_AR_RECOIL		= 4,
	weapondata_AR_WIDTH		= 20,
	weapondata_AR_HEIGHT		= 8;

// "deagle" behavior
int weapondata_PISTOL_DISCHARGE = 100,
	weapondata_PISTOL_PULLOUT   = 40,
	weapondata_PISTOL_RANGE	 = 300,
	weapondata_PISTOL_DAMAGE	 = 30,
	weapondata_PISTOL_RELOAD	 = 240,
	weapondata_PISTOL_BSPEED	 = 50,
	weapondata_PISTOL_USES		 = 5,
	weapondata_PISTOL_RECOIL	 = 80,
	weapondata_PISTOL_WIDTH	 = 14,
	weapondata_PISTOL_HEIGHT	 = 7;

int weapondata_WeaponProperties[4][10];

void weapondata_InitializeSystem() {
	weapondata_WeaponProperties[1][0] = weapondata_AR_DISCHARGE;
	weapondata_WeaponProperties[1][1] = weapondata_AR_PULLOUT;
	weapondata_WeaponProperties[1][2] = weapondata_AR_RANGE;
	weapondata_WeaponProperties[1][3] = weapondata_AR_DAMAGE;
	weapondata_WeaponProperties[1][4] = weapondata_AR_RELOAD;
	weapondata_WeaponProperties[1][5] = weapondata_AR_BSPEED;
	weapondata_WeaponProperties[1][6] = weapondata_AR_USES;
	weapondata_WeaponProperties[1][7] = weapondata_AR_RECOIL;
	weapondata_WeaponProperties[1][8] = weapondata_AR_WIDTH;
	weapondata_WeaponProperties[1][9] = weapondata_AR_HEIGHT;

	weapondata_WeaponProperties[2][0] = weapondata_PISTOL_DISCHARGE;
	weapondata_WeaponProperties[2][1] = weapondata_PISTOL_PULLOUT;
	weapondata_WeaponProperties[2][2] = weapondata_PISTOL_RANGE;
	weapondata_WeaponProperties[2][3] = weapondata_PISTOL_DAMAGE;
	weapondata_WeaponProperties[2][4] = weapondata_PISTOL_RELOAD;
	weapondata_WeaponProperties[2][5] = weapondata_PISTOL_BSPEED;
	weapondata_WeaponProperties[2][6] = weapondata_PISTOL_USES;
	weapondata_WeaponProperties[2][7] = weapondata_PISTOL_RECOIL;
	weapondata_WeaponProperties[2][8] = weapondata_PISTOL_WIDTH;
	weapondata_WeaponProperties[2][9] = weapondata_PISTOL_HEIGHT;
	weapons_WeaponUsesLeft[0] = 0;
	weapons_WeaponUsesLeft[1] = weapondata_AR_USES;
	weapons_WeaponUsesLeft[2] = weapondata_PISTOL_USES;
}
