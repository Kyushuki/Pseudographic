#include <iostream>
#include <math.h>

using namespace std; //эта версия ветки не имеет каких-либо изменений, по сравнению с GraphArray потому что создал её поздно ночью и хочу спать

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

	string GraphA[stepCount + 2][maxNormY + 2];

	for (int i = 0; i <= stepCount + 1; i++) { //заполняет массив пустыми значениями(пробелами)
		for (int j = 0; j <= maxNormY + 1; j++) {
			GraphA[i][j] = " ";
		}
	}
	for (int j = 0; j <= maxNormY + 2; j++) { //заполняет ось ОУ в массиве
		GraphA[0][j] = "|";
	}

	for (int i = 0; i <= stepCount + 1; i++) { //заполняет ось ОХ в массиве
		GraphA[i][0] = "-";
	}
	for (int i = 0; i <= stepCount + 1; i++) { //заполняет массив значениями графика
		for (int j = 0; j <= maxNormY + 1; j++) {
			if (j == normalY[i]) {

				if (normalY[i] == minNormY) { // проверка на минимальное значение по оси у
					GraphA[i + 1][j + 1] = "%";
				}
				else if (normalY[i] == maxNormY) { //проверка на максимальное значение по оси х
					GraphA[i + 1][j + 1] = "#";
				}
				else {
					GraphA[i + 1][j + 1] = "*";
				}
			}
		}
	}
	GraphA[0][maxNormY + 1] = "Y";
	GraphA[stepCount + 1][0] = "X";

	string copiedGraphA[maxNormY + 2][maxNormY + 2]; //поворачивает график функции
	for (int i = 0; i <= maxNormY + 1; i++) {
		for (int j = 0; j <= stepCount + 1; j++) {
			copiedGraphA[i][j] = GraphA[j][maxNormY + 1 - i];
		}
	}
	for (int i = 0; i <= maxNormY + 1; i++) { //рисует массив - график функции
		for (int j = 0; j <= maxNormY + 1; j++) {
			cout << copiedGraphA[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	drawSymbolPlot(linear, -5, 5, 10);
	drawSymbolPlot(cube, -2, 2, 10);
	drawSymbolPlot(parabola, -5, 5, 20);

}