#include "RectangleSolver.h"
bool ArraySwap(int i, int j, POINT array[ARRAY_LENGTH]) {
	float tempx = array[i].x;
	float tempy = array[i].y;
	array[i].x = array[j].x;
	array[i].y = array[j].y;
	array[j].x = tempx;
	array[j].y = tempy;
	return true;
}
bool Sorting(POINT array[ARRAY_LENGTH]) {
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j <= 3; j++) {
			if (array[i].x > array[j].x)
				ArraySwap(i, j, array);
			else if (array[i].x == array[j].x) {
				if (array[i].y > array[j].y)
					ArraySwap(i, j, array);
			}
		}
	}
}