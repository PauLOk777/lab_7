30. 	Заданий масив Y(n) дійсних чисел, серед яких є і від’ємні. 
Упорядкувати його елементи за зменшенням та знайти суму тих елементів упорядкованого масиву Y, що знаходяться на парних позиціях.
//////////////////////////////

#include "pch.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

void input();
void output();
void sorted();
double sum(double* pArr);

int main() {
	const int N = 15;
	double Y[N];
	double *p = Y;
	input();
	output();
	sorted();
	output();
	cout << endl;
	cout << "Sum: " << sum(p) << endl;
	
	return 0;
}

void input() {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		Y[i] = rand() % 19 -9;
	}
}

void output() {
	cout << "Y: ";
	for (int i(0); i < N; i++) {
		cout << Y[i] << " ";
	}
	cout << endl;
}

void sorted() {
	double t;
	for (int i(0); i < N; i++) {
		for(int j(0); j < N-1-i; j++)
			if (Y[j] < Y[j+1]) {
				t = Y[j];
				Y[j] = Y[j+1];
				Y[j+1] = t;
			}
	}
}

double sum(double *pArr) {
	double s = 0.0;
	for (int i(0); i < N; i++) {
		if (i % 2 == 1) {
			s += Y[i];
		}
	}
	return s;
}
