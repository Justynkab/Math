#include "n_root.h"
#include "equation2.h"
#include "equation3.h"
#include "equation4.h"
#include "cplx.h"
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	
	test_get_fi(cplx(sqrt(3)), 0);
	test_get_fi(cplx(sqrt(3),1), M_PI / 6);
	test_get_fi(cplx(0,1), M_PI_2);
	test_get_fi(cplx(-sqrt(3),1), M_PI * 5 / 6);
	test_get_fi(cplx(-sqrt(3)), M_PI);
	test_get_fi(cplx(-sqrt(3),-1), M_PI * 7/6);
	test_get_fi(cplx(0,-1), M_PI *3/2);
	test_get_fi(cplx(sqrt(3),-1), M_PI * 11/6);
	test_get_fi(cplx(0), 0);

	test_n_root(8, 4);
	test_n_root(8, 3);
	test_n_root(-8, 3);
	test_n_root(16, 4);
	test_n_root(-32, 5);

	test_n_root(cplx(8, 0), 3);
	test_n_root(cplx(- 8, 0), 3);
	test_n_root(cplx(16, 0), 4);
	test_n_root(cplx(- 32,0), 5);

	test_n_root(cplx(8, 2), 3);
	test_n_root(cplx(-8, -8), 3);
	test_n_root(cplx(16, -4), 4);
	test_n_root(cplx(-32, 32), 5);

	test_n_root(cplx(0, 0), 4);
	test_n_root(cplx(0, 32), 5);
	test_n_root(cplx(0, -32), 5);

	test_equation2(1, -2, 1);
	test_equation2(1, 2, 1);
	test_equation2(1, 0, 4);
	test_equation2(1, 0, -4);
	test_equation2(-43.43, -46, 0);
	test_equation2(0, -2, 1);
	test_equation2(1, -6, 9);
	test_equation2(0, 0, 1);
	test_equation2(0, 0, 0);

	test_equation3(1, 0, 0, -8);
	test_equation3(2, -11, 16, 22);
	test_equation3(1, -6, 11, -6);
	test_equation3(1, 43, 0, -8);
	test_equation3(1,0,-3,1);


	test_equation4(1, -4, 6, 15, 1);
	test_equation4(1, 8, -6, 15, 1);
	test_equation4(1, -4, 6, -4, 1);
	test_equation4(1, 4, 6, 4, 1);
	test_equation4(1, 8, 9, 90, -1);
	test_equation4(1, 0, 0, 0, 16);
	test_equation4(1, 0, 2, 0, 1);
}