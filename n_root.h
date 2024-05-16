#pragma once
#include "cplx.h"


// helper functions to test n_root functions
cplx power_n(cplx x, int n);
cplx power_2(cplx x);
cplx power_3(cplx x);
cplx power_4(cplx x);

void n_root(cplx result[], double x, int n);
void n_root(cplx result[], cplx z, int n);

void test_n_root(double x, int n);
void test_n_root(cplx z, int n);