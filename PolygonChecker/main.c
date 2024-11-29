#include <stdio.h>
#include <stdbool.h>
#include "RectangleSolver.h"
#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	POINT array[ARRAY_LENGTH] = { 0 };
	float length[SIDE_LENGTH] = { 0 };
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			if (result != "Not a triangle") { 
				printf_s("The angle in turn %f %f %f", AngleSolver(triangleSides[0], triangleSides[2], triangleSides[1]),
					AngleSolver(triangleSides[1], triangleSides[0], triangleSides[2]),
					AngleSolver(triangleSides[2], triangleSides[1], triangleSides[0]));	
			}
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			RectangleInput(array);
			if (CalculateRectangle(array, length)) {
				printf("\nShape is rectangle\n");
				printf("It's perimeter is: %f\n", PerimeterCalculate(length));
				printf("It's area is: %f\n", AreaCalculate(length));
			}
			else {
				printf("\nShape is not rectangle\n");
				printf("It's perimeter is: %f\n", PerimeterCalculate(length));
			}
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}