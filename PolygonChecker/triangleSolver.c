#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"
#define M_PI 3.14159265358979323846
char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1+side2 <= side3 || side1 + side3 <= side2 || side3 + side2 <= side1) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else if (side1 * side1 + side2 * side2 == side3 * side3 || side1 * side1 + side3 * side3 == side2 * side2 || side3 * side3 + side2 * side2 == side1 * side1) {
		result = "Right triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

float AngleSolver(int side1, int side2, int side3) {
	float result = acos(((side2 * side2 + side3 * side3 - side1 * side1)/(2.0*side2*side3)))*180/M_PI;
	return result;
}