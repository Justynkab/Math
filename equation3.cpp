#include "equation3.h"
#include "n_root.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

void substitute_z(cplx result[3], double A, double B) {
	for (int i = 0; i < 3; i++) {
		result[i] = result[i] + cplx(-B / (3 * A), 0);
	}
}

void solve_tryg(cplx result[3], double a, double b) {
	double r = sqrt(-a);
	double fi = acos(-b / (r * r * r));

	for (int i = 0; i < 3; i++) {
		result[i].real = 2 * r * cos(fi / 3 + (i - 1) * 2 * M_PI / 3);
		result[i].imag = 0;
	}
}

void easy_solution(cplx result[3], double a, double b) {
	if (a == 0 && b == 0) {
		result[0] = cplx(0, 0);
		result[1] = cplx(0, 0);
		result[2] = cplx(0, 0);
	}
	else if (a == 0) {
		n_root(result, -2 * b, 3);
	}
	else {
		result[0] = cplx(0, 0);
		n_root(result + 1, -3 * a, 2);
	}

}

void solve_cardan(cplx result[3], double a, double b) {
	double square_root = sqrt(b * b + a * a * a);
	cplx first_cube_root[3], second_cube_root[3];
	n_root(first_cube_root, -b + square_root, 3);
	n_root(second_cube_root, -b - square_root, 3);

	int k = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cmp(first_cube_root[i] * second_cube_root[j], cplx(-a))) {
				result[k] = first_cube_root[i] + second_cube_root[j];
				k++;
				if (k == 3) {
					j = 4;
					i = 4;
				}
			}
		}
	}
	assert(k == 3);
}

void equation3(cplx result[3], double A, double B, double C, double D) {
	double p, q, a, b;
	p = -B * B / (3 * A * A) + C / A;
	q = 2 * B * B * B / (27 * A * A * A) - B * C / (3 * A * A) + D / A;
	a = p / 3;
	b = q / 2;
	double pom = b * b + a * a * a;
	if (a * b == 0) {
		cout << "a lub b rowne 0" << endl;
		easy_solution(result, a, b);
	}
	else if ((b * b + a * a * a) < 0) {
		cout << "Warunek jest spelniony, sa 3 pierwiastki rzeczywiste." << endl;
		solve_tryg(result, a, b);
	}
	else {
		cout << "Cardan dla 3" << endl;
		solve_cardan(result, a, b);
	}
	substitute_z(result, A, B);
}
