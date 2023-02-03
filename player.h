// "player.h" for the player controller
#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

#include "src/libs/raylib.h"

extern Vector2  player_PlayerPosition,
                player_PlayerPosOffset,
                player_TopLeft,
                player_TopRight,
                *player_BottomLeft,
                player_BottomRight,
                player_PlayerCenter;
    
extern int      player_PlayerPreventMovement,
                player_PlayerSideLength,
                // jumping variables
                player_PlayerJumping,
	            player_PlayerMaxTime,
                // strafing variables
                player_PlayerSpeed,
                player_PlayerAcceleration,
                // PlayerDirection keeps last direction after done strafing
                // 0  = no direction yet
                // -1 = left
                // 1  = right
                player_PlayerDirection,
                player_PlayerStrafeTime,
                player_PlayerMaxStrafeTime;

// Updates the status of the stafe keys eg. A/D
// and updates PlayerDirection and PlayerAcceleration based on input
void player_UpdateStrafingVelocity(int accelerationDesired);

// Runs UpdatePlayerStrafing and sets PlayerPosition based on variable changes
void player_UpdateMovement();

// Updates all TopRight...BottomRight variables
// Draws player square
void player_Draw();

#endif
