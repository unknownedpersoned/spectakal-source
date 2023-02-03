cd src
gcc -g -o ../build/out main.c game.c gridmap.c gui.c bulletlogic.c input.c particle.c player.c weapondata.c weapons.c -O1 -Wall -std=c99 -Wno-missing-braces -I libs/ -L ../build/ -lGL -lraylib -lm -lpthread -ldl -lstdc++ -lrt -lX11 
cd ../build

