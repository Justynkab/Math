#include "equation3.h"
#include "n_root.h"
#include <cassert>

void test_equation3(double A, double B, double C, double D) {
	cplx result[3];
	equation3(result, A, B, C, D);
	for (int i = 0; i < 3; i++) {
		cplx x = result[i];
		cplx y = cplx(A) * power_3(x) + cplx(B) * power_2(x) + cplx(C) * x + cplx(D);
		cout << "y[" << i << "], x=" << x << ": " << y << endl;
		assert(y.cplx_abs() < cplx::epsilon);
	}
}