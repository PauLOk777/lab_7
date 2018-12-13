30. 	Заданий масив Y(n) дійсних чисел, серед яких є і від’ємні. 
Упорядкувати його елементи за зменшенням та знайти суму тих елементів упорядкованого масиву Y, що знаходяться на парних позиціях.
//////////////////////////////

#include "pch.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

void input(double *pArr, const int a);
void output(double *pArr, const int a);
void sorted(double *pArr, const int a);
double sum(double* pArr, const int a);

int main() {
	const int N = 15;
	double Y[N];
	double *p = Y;
	input(p, N);
	output(p, N);
	sorted(p, N);
	output(p, N);
	cout << endl;
	cout << "Sum: " << sum(p, N) << endl;

	return 0;
}

void input(double *pArr, const int a) {
	srand(time(NULL));
	for (int i = 0; i < a; i++) {
		pArr[i] = rand() % 19 - 9;
	}
}

void output(double *pArr, const int a) {
	cout << "Y: ";
	for (int i(0); i < a; i++) {
		cout << pArr[i] << " ";
	}
	cout << endl;
}

void sorted(double *pArr, const int a) {
	double t;
	for (int i(0); i < a; i++) {
		for (int j(0); j < a - 1 - i; j++)
			if (pArr[j] < pArr[j + 1]) {
				t = pArr[j];
				pArr[j] = pArr[j + 1];
				pArr[j + 1] = t;
			}
	}
}

double sum(double *pArr, const int a) {
	double s = 0.0;
	for (int i(0); i < a; i++) {
		if (i % 2 == 1) {
			s += pArr[i];
		}
	}
	return s;
}
