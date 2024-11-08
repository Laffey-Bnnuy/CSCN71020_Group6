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
bool InputCheck(int n, float Input1, float Input2, POINT array[ARRAY_LENGTH]) {
	for (int i = 0; i < n; i++) {
		if (Input1 == array[i].x && Input2 == array[i].y)
			return false;
	}
	return true;
}
void RectangleInput(POINT array[ARRAY_LENGTH]) {
	float Input1 = 0;
	float Input2 = 0;
	char Input[4][STRING_LENGTH] = { "first","second","third","forth" };
	printf("Print the coordinate x y seperate by a space\n");
	int i = 0;
	while (i < ARRAY_LENGTH) {
		printf("Input the %s point: ", Input[i]);
		int item = scanf_s("%f%f", &array[i].x, &array[i].y);
		if (item == 2) {
			if (InputCheck(i, array[i].x, array[i].y, array))
				i++;
		}
		else {
			int item2 = getchar();
			while ((getchar() != '\n'));
			printf("Please enter a number!!!\n");
		}
	}
}
bool CalculateRectangle(POINT array[ARRAY_LENGTH], float length[SIDE_LENGTH]) {
	Sorting(array);
	length[0] = sqrt((array[1].x - array[0].x) * (array[1].x - array[0].x) + (array[1].y - array[0].y) * (array[1].y - array[0].y));
	length[1] = sqrt((array[3].x - array[1].x) * (array[3].x - array[1].x) + (array[3].y - array[1].y) * (array[3].y - array[1].y));
	length[2] = sqrt((array[3].x - array[2].x) * (array[3].x - array[2].x) + (array[3].y - array[2].y) * (array[3].y - array[2].y));
	length[3] = sqrt((array[2].x - array[0].x) * (array[2].x - array[0].x) + (array[2].y - array[0].y) * (array[2].y - array[0].y));
	length[4] = sqrt((array[1].x - array[2].x) * (array[1].x - array[2].x) + (array[1].y - array[2].y) * (array[1].y - array[2].y));
	length[5] = sqrt((array[0].x - array[3].x) * (array[0].x - array[3].x) + (array[0].y - array[3].y) * (array[0].y - array[3].y));

	if (length[0] == length[2] && length[1] == length[3] && length[4] == length[5]) {
		return true;
	}
	return false;
	for (int i = 0; i < 4; i++) {
		printf("%f %f\n", array[i].x, array[i].y);
	}
}
float AreaCalculate(float length[SIDE_LENGTH]) {
	return length[0] * length[1];
}
float PerimeterCalculate(float length[SIDE_LENGTH]) {
	return length[0] + length[1] + length[2] + length[3];
}
