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
	double maxNormY = normalY[0];
	for (int i = 0; i <= stepCount; i++) {  // находит максимальное значение у
		if (normalY[i] > maxNormY) {
			maxNormY = normalY[i];
		}
	}
	for (int j = 0; j <= maxNormY - 1; j++) { // печатает ветку оси OY
		cout << "_";
	}
	cout << "_ y" << endl;
	for (int i = 0; i <= stepCount; i++) {    // выводит функцию

		cout << "|";                          // вывод части рамки по оси х
		for (int k = 0; k <= normalY[i] - 1; k++) {
			cout << ' ';
		}
		if (normalY[i] == minNormY) { // проверка на минимальное значение по оси у
			cout << "%" << endl;
		}
		else if (normalY[i] == maxNormY) { //проверка на максимальное значение по оси х
			cout << "#" << endl;
		}
		else {
			cout << '*' << endl;
		}

	}
	cout << "x" << endl;
}

int main()
{
	cout << "Справка: % - минимальное значение OY; # - максимальное значение OY" << endl;
	drawSymbolPlot(parabola, -5, 5, 20);
	drawSymbolPlot(linear, -5, 5, 10);
	drawSymbolPlot(cube, -3.5, 3.5, 20);
	return 0;
}

