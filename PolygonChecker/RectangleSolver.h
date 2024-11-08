#pragma once
#include <stdbool.h>
#define ARRAY_LENGTH 4
#define SIDE_LENGTH 6
#define STRING_LENGTH 100
typedef struct Point {
	float x;
	float y;
}POINT;
bool ArraySwap(int i, int j, POINT array[ARRAY_LENGTH]);
bool Sorting(POINT array[ARRAY_LENGTH]);