// "main.c" probably ignore this file unless ur modding
#include "../game.h"

int main() {
    if (!game_Initialize()) return -1;
    game_Run();
    //FreeMemory();
    return 0;
}
 
