#include "equation2.h"
#include "n_root.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

void equation2(cplx result[2], double A, double B, double C)
{
	if (A == 0 && B == 0 && C == 0) {
		cout << "Always true" << endl;
		result[0] = cplx(0);
		result[1] = cplx(0);
		return;
	}
	else if (A == 0 && B == 0) {
		cout << "Never true" << endl;
		result[0] = cplx(0);
		result[1] = cplx(0);
		return;
	}
	else if (A == 0) {
		cout << "Linear equation" << endl;
		result[0] = cplx(-C/B);
		result[1] = cplx(-C/B);
		return;
	}
	cout << "Quadratic equation" << endl;
	double delta = B * B - 4 * A * C;
	cplx delta_sqrt[2];
	n_root(delta_sqrt, delta, 2);
	result[0] = (cplx(-B) + delta_sqrt[0]) / cplx(2 * A);
	result[1] = (cplx(-B) + delta_sqrt[1]) / cplx(2 * A);
	
}
