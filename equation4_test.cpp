#include "equation4.h"
#include "n_root.h"
#include <cassert>

void test_equation4(double A, double B, double C, double D, double E)
{
	cplx result[4];
	equation4(result, A, B, C, D, E);
	for (int i = 0; i < 4; i++) {
		cplx x = result[i];
		cplx y = cplx(A) * power_4(x) + cplx(B) * power_3(x) + cplx(C) * power_2(x) + cplx(D) * x + cplx(E);
		cout << "y[" << i << "], x=" << x << ": " << y << endl;
		assert(y.cplx_abs() < cplx::epsilon);
	}
}