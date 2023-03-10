#include <iostream>
#include <math.h>

using namespace std;

double linear(double x) {
	return x;
}

double parabola(double x) {
	return x * x;
}

double cube(double x) {
	return x * x * x;
}

void drawSymbolPlot(double(&func)(double), double xMax, double xMin, int stepCount) {

	double Step = (xMin - xMax) / stepCount;
	double x[stepCount];
	double y[stepCount];
	for (int i = 0; i <= stepCount; i++) { //задаёт размер графика
		x[i] = (Step * i + xMax);
		y[i] = func(x[i]);
	}

	double miny = y[0];
	for (int i = 0; i <= stepCount; i++) {  // находит минимальное значение у
		if (y[i] < miny) {
			miny = y[i];
		}
	}

	double Y[stepCount];
	double normalY[stepCount];
	for (int i = 0; i <= stepCount; i++) { // позволяет вывести отрицательные значения у
		Y[i] = trunc(y[i]);
		normalY[i] = Y[i] - miny;
	}
	double minNormY = normalY[0];
	for (int i = 0; i <= stepCount; i++) {  // находит минимальное значение у
		if (normalY[i] < minNormY) {
			minNormY = normalY[i];
		}
	}
	int maxNormY = normalY[0];
	for (int i = 0; i <= stepCount; i++) {  // находит максимальное значение у
		if (normalY[i] > maxNormY) {
			maxNormY = normalY[i];
		}
	}

	string GraphA[stepCount + 1][maxNormY + 1];

	for (int i = 0; i <= stepCount; i++) {
		for (int j = 0; j <= maxNormY; j++) {
			GraphA[i][j] = " ";
		}
	}
	for (int i = 0; i <= stepCount; i++) {
		for (int j = 0; j <= maxNormY; j++) {
			if (j == normalY[i]) {
				GraphA[i][j] = "*";
			}
		}
	}
	for (int i = 0; i <= stepCount; i++) {
		for (int j = 0; j <= maxNormY; j++) {
			cout << GraphA[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	drawSymbolPlot(cube, -3, 3, 10);
	drawSymbolPlot(parabola, -5, 5, 20);
	drawSymbolPlot(linear, -5, 5, 10);
}
