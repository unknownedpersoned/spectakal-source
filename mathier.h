// "mathier.h" contains useful math functions used in the game
#ifndef INCLUDE_MATHIER_H
#define INCLUDE_MATHIER_H

typedef struct VectorInt2 {
    int x;
    int y;
} VectorInt2;

inline int btwn(int a, int b, int c) {
    return (a > b && a < c);
}

#endif