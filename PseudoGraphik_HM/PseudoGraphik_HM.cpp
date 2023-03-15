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
	cout << " % - минимальное значение по Y, # - максимальное значение по Y";
}
void funcInput(int x) {
	double n, m;
	int y;
	if (x == 1) {
		system("clear");
		cout << "Введите параметры вывода функции:\n Область определения:\n Минимальное значение X: ";
		cin >> n;
		cout << "Максимальное значение X: ";
		cin >> m;
		cout << "Шаг: ";
		cin >> y;
		system("clear");
		drawSymbolPlot(linear, n, m, y);
	}
	else if (x == 2) {
		system("clear");
		cout << "Введите параметры вывода функции:\n Область определения:\n Минимальное значение X: ";
		cin >> n;
		cout << "Максимальное значение X: ";
		cin >> m;
		cout << "Шаг: ";
		cin >> y;
		system("clear");
		drawSymbolPlot(parabola, n, m, y);
	}
	else if (x == 3) {
		system("clear");
		cout << "Введите параметры вывода функции:\n Область определения:\n Минимальное значение X: ";
		cin >> n;
		cout << "Максимальное значение X: ";
		cin >> m;
		cout << "Шаг: ";
		cin >> y;
		system("clear");
		drawSymbolPlot(cube, n, m, y);
	}
}
int main(int x)
{
	int y = 1;
	int system_checkout = 0;
	int system_graphout = 0;
	while (y == 1) {

		if (system_checkout == 0) {
			system("clear");
			cout << "Добро пожаловать в Графики функций\n 1 - Выбор функции\n 2 - Справка\n Пожалуйста, введите необходимое значение, чтобы продолжить: ";
			cin >> system_checkout;
		}
		else if (system_checkout == 1) {
			system("clear");
			cout << "Вы можете выбрать 3 стандартные функции:\n 1 - Линейная функция \n 2 - парабола\n 3 - кубическая парабола\n Введите необходимое значение, чтобы продолжить: ";
			cin >> system_graphout;
			funcInput(system_graphout);
			break;	
		}
		else if (system_checkout == 2) {
			system("clear");
			cout << "На данный момент программа работает на со всеми функциями\n и не имеет различного полезного функционала\n Однако я работаю над тем, чтобы программа имела в своём составе этот самый функционал\n и работала корректно." << endl;
			cout << "За всеми изменениями и продвижениями программы вы можете наблюдать в репозитории на гитхаб 'PseudoGraphik_HM' @Kyushuki" << endl;
			cout << "Для упрощения поисков вот ссылка на репозиторий - https://github.com/Kyushuki/PseudoGraphik_HM" << endl;
			cout << "Чтобы выйти обратно в меню введите 0 : ";
			cin >> system_checkout;
		}
		
	}
}

