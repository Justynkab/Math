#pragma once

#include <iostream>

using namespace std;

class cplx {

public:
	double real;
	double imag;

	cplx();

	cplx(double real, double imag = 0);

	double cplx_abs() const;

	cplx operator+(cplx c);

	cplx operator-(cplx c);

	cplx operator*(cplx c);

	cplx operator/(cplx c);

	bool operator==(cplx c);

	cplx operator=(cplx c);

	double get_r();

	double get_fi();



	friend ostream& operator<<(ostream& os, const cplx c);

	static const double epsilon;

};

bool cmp(cplx a, cplx b);

void test_get_fi(cplx z, double fi);



