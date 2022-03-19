#include<iostream>
#include<cmath>
#include<cstdlib> 
using namespace std;

double f(double x) {
	double f;
	if (x == 0) {
		f = 0.6; // По первому замечательному пределу.
	}
	else {
		f = sin(0.6 * x) / x;
	}
	return f;
}


double fun(int a, double b, int n) {

	double Ai[5] = { 0.2369268850, 0.4786286705, 0.5688888889, 0.4786286705, 0.2369268850 }; // при m = 4 (Коэффициенты из таблицы)
	double Xg[5] = { -0.9061798459, -0.5384693101, 0, 0.5384693101, 0.9061798459 };// при m = 4 (Коэффициенты из таблицы)
	cout << Ai[1];
	double h = (b - a) / n;
	double z;
	z = 0;
	double x1;
	x1 = a + 0.5 * h;
	double x;

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 5; i++) {
			x = x1 + 0.5 * h * Xg[i];
			z = z + Ai[i] * f(x);
			cout << z << endl;
		}
		x1 = x1 + h;
	}
	double y;
	y = z * 0.5 * h;
	return y;
}
//квадратурная формула Гаусса точнее чем Ньютона Котоса, т.к. многочлены получаются более высокого порядка.
int main() {
	setlocale(LC_ALL, "Russian");


	int a;
	double b;
	int n;
	double eps;
	cout << "Введите отрезок: ";
	cin >> a;
	cin >> b;
	cout << "Введите число частичных отрезков n: ";
	cin >> n;
	cout << "Введите число останова eps: ";
	cin >> eps;


	double y1;
	y1 = fun(a, b, n);
	n = n * 2;
	double y2;
	y2 = fun(a, b, n);
	while (abs(y2 - y1) >= eps) {
		y1 = y2;
		n = n * 2;
		y2 = fun(a, b, n);
	}

	cout << "Ответ: " << y1 << endl;
	cin.get();
	cin.get();
}