// "player.c" for the player controller
#include "../player.h"

#include "libs/raylib.h"
#include "../input.h"

Vector2 
    player_PlayerPosition          = {500, 505},
    player_PlayerPosOffset         = {0, 0},
    player_TopLeft                 = {0, 0},
    player_TopRight                = {0, 0},
    *player_BottomLeft             = &player_PlayerPosition,
    player_BottomRight             = {0, 0},
    player_PlayerCenter            = {0, 0};
    
int player_PlayerPreventMovement   = 0,
    player_PlayerSideLength        = 40,
    player_PlayerJumping           = 0,
	player_PlayerMaxTime           = 90,
    player_PlayerSpeed             = 9,
    player_PlayerAcceleration      = 8,
    player_PlayerDirection         = 0,
    player_PlayerStrafeTime        = 0,
    player_PlayerMaxStrafeTime     = 14;

static int *PSL = &player_PlayerSideLength;

void player_UpdateStrafingVelocity(int accelerationDesired) {
    if (accelerationDesired) {
        if (player_PlayerStrafeTime < player_PlayerMaxStrafeTime)
            player_PlayerStrafeTime++;
        if (player_PlayerAcceleration && !(player_PlayerStrafeTime % 2))
            player_PlayerAcceleration--;
        return;
    }
    if (player_PlayerAcceleration < player_PlayerSpeed) {
        player_PlayerStrafeTime--;
        if (!(player_PlayerStrafeTime % 2))
            player_PlayerAcceleration++;
    }
}

void player_UpdateMovement() {
    if (
        !player_PlayerPreventMovement 
        && 
        !input_CheckDown(Inputs_CONTROL_MOVE_B)
    ) {
        int accelerationDesired = input_CheckDown(Inputs_CONTROL_MOVE_A);
        if (accelerationDesired) {
            // 5 here turns CONTROL_LEFT/RIGHT into -1 and 1, which are direction codes.
            player_PlayerDirection = input_GetButtonDown() - 5;
        }
        player_UpdateStrafingVelocity(accelerationDesired);
        // run calculation on newly updated variables
        player_PlayerPosition.x += player_PlayerDirection * (player_PlayerSpeed - player_PlayerAcceleration);
    }
}

void player_Draw() {  
	player_TopRight     = (Vector2){player_PlayerPosition.x + *PSL, player_PlayerPosition.y - *PSL}; 
    player_TopLeft      = (Vector2){player_PlayerPosition.x, player_PlayerPosition.y - *PSL}; 
    // BottomLeft is a pointer to PlayerPosition, so assignment not required
    player_BottomRight  = (Vector2){player_PlayerPosition.x + *PSL, player_PlayerPosition.y};
	player_PlayerCenter = (Vector2){player_BottomLeft->x + *PSL/2, player_BottomLeft->y - *PSL/2 };
	DrawRectangle(player_TopLeft.x, player_TopLeft.y, *PSL, *PSL, WHITE);
	//DrawTriangle(TopRight, (Vector2){PlayerPosition.x + PSL, PlayerPosition.y}, *BottomLeft, WHITE);
    //DrawTriangleLines((Vector2){TopRight.x-5, TopRight.y}, TopLeft, (Vector2){BottomLeft->x, BottomLeft->y-5}, WHITE);

    // temp line for "collision testing"
    DrawLine(0, 505, 1000, 505, WHITE);
    if (1) {
    	DrawRectangle(player_TopLeft.x, player_TopLeft.y, 10, 10, RED);
    	DrawRectangle(player_TopRight.x - 10, player_TopRight.y, 10, 10, GREEN);
    	DrawRectangle(player_BottomLeft->x, player_BottomLeft->y - 10, 10, 10, BLUE);
    	DrawRectangle(player_BottomRight.x - 10, player_BottomRight.y - 10, 10, 10, PURPLE);
    }
    return;
}
