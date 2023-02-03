// "game.h" basic game-running stuff
#ifndef INCLUDE_GAME_H
#define INCLUDE_GAME_H

#define Global_ResX 900
#define Global_ResY 900
#define Global_TargetFPS 60

extern int Global_FrameCount;

void game_UpdateFrameCount();

// Initialize window and other stuff
int game_Initialize();

// Main game loop, exits when window recieves close signal
void game_Run();

// Free allocated stuff
//void FreeMemory();

#endif
