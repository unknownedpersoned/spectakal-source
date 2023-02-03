// "gridmap.h" for mapbuilding/particles
#ifndef INCLUDE_GRIDMAP_H
#define INCLUDE_GRIDMAP_H

extern const int gridmap_SQUARE_SIDELENGTH;

/* Aligns point on X axis to increment of GRIDMAP_SQUARE_SIDELENGTH */
int gridmap_AlignToSquareX(int x);
/* Aligns point on Y azis to increment of GRIDMAP_SQUARE_SIDELENGTH */
int gridmap_AlignToSquareY(int y);
#define atgsX(x) gridmap_AlignToSquareX(x)
#define atgsY(y) gridmap_AlignToSquareY(y)


#endif

