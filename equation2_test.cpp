#include "equation2.h"
#include "n_root.h"
#include <cassert>

void test_equation2(double A, double B, double C) {
	if (A == 0 && B == 0 && C != 0) {
		cout << "Never true" << endl;
		return;
	}
	cplx result[2];
	equation2(result, A, B, C);
	for (int i = 0; i < 2; i++) {
		cplx x = result[i];
		cplx y = cplx(A) * power_2(x) + cplx(B) * x + cplx(C);
		cout << "y[" << i << "], x=" << x << ": " << y << endl;
		assert(y.cplx_abs() < cplx::epsilon);
	}
}