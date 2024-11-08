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
void RectangleInput(POINT array[ARRAY_LENGTH]);
bool CalculateRectangle(POINT array[ARRAY_LENGTH], float length[SIDE_LENGTH]);
float AreaCalculate(float length[SIDE_LENGTH]);
float PerimeterCalculate(float length[SIDE_LENGTH]);
bool InputCheck(int n, float Input1, float Input2, POINT array[ARRAY_LENGTH]);