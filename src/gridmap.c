// "gridmap.c" for mapbuilding/particles
#include "../gridmap.h"

#include "libs/raylib.h"

const int gridmap_SQUARE_SIDELENGTH = 4;

int gridmap_AlignToSquareX(int x) {
	if (x % gridmap_SQUARE_SIDELENGTH == 0) return x;
	for (int i = 1; i < gridmap_SQUARE_SIDELENGTH; i++) {
		x--;
		if (x % gridmap_SQUARE_SIDELENGTH == 0 && i <= gridmap_SQUARE_SIDELENGTH / 2)
			return x; 
	}
	return x + gridmap_SQUARE_SIDELENGTH;
}

int gridmap_AlignToSquareY(int y) {
	if (y % gridmap_SQUARE_SIDELENGTH == 0) return y;
	for (int i = 1; i < gridmap_SQUARE_SIDELENGTH; i++) {
		y--;
		if (y % gridmap_SQUARE_SIDELENGTH == 0 && i <= gridmap_SQUARE_SIDELENGTH / 2)
			return y; 
	}
	return y + gridmap_SQUARE_SIDELENGTH;
}