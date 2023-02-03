// "game.c" basic game-running stuff
#include "../game.h"

#include <stdio.h>

//#include "../discord.h"
//#include "../mathier.h"
#include "../bulletlogic.h"
#include "../particle.h"
#include "../player.h"
#include "../weapons.h"
#include "../weapondata.h"
#include "../input.h"
#include "../gridmap.h"
#include "../gui.h"
#include "libs/rawdraw_sf.h"

int Global_FrameCount = 1;

void game_UpdateFrameCount() {
    if (Global_FrameCount <= Global_TargetFPS)
        Global_FrameCount++;
    else Global_FrameCount = 1;
}

int game_Initialize() {
    InitAudioDevice();
    InitWindow(Global_ResX, Global_ResY, "demo");
    SetConfigFlags(FLAG_MSAA_4X_HINT|FLAG_VSYNC_HINT);
    SetTargetFPS(Global_TargetFPS);
    DisableCursor();
    SetWindowIcon(LoadImage("resources/icon.png"));
    weapondata_InitializeSystem();
    weapons_SwapHeld(Weapon_PISTOL);
    particle_Initialize();
    return 1;
}

void game_Run() {
    while (!WindowShouldClose()) {

        // Update
        input_UpdateMouseVariables(1);
        if (input_MRD) particle_SummonParticle(input_GetMXY(), ParticleType_Basic, ParticleColor_Sand);
        weapons_UpdateWeaponInput();
        weapons_UpdateWeaponRotation();
        weapons_UpdateWeaponLogic();
        bulletlogic_UpdateAndDrawBullets();
        player_UpdateMovement();
        BeginDrawing();
        ClearBackground(BLACK);
        particle_UpdateAll();
        DrawText(TextFormat("%d %d\n%d %d %d\n%d", particle_ParticleCountAll, weapons_WeaponRotation, input_MRD, atgsX(input_MX) / 4, atgsY(input_MY) / 4, input_CheckDown(Inputs_CONTROL_MOVE_B)), 0, 0, 24, WHITE);
        player_Draw();
        weapons_DrawWeapon();
        input_DrawCursor();
        EndDrawing();
        game_UpdateFrameCount();
    }
    CloseAudioDevice();
    CloseWindow();
}
