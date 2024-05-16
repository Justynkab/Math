#include "cplx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

const double cplx::epsilon = 1e-11;

cplx::cplx() {
	cplx(0, 0);
}

cplx::cplx(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

double cplx::cplx_abs() const {
	return sqrt(real * real + imag * imag);
}

cplx cplx::operator+(cplx c) {
	cplx temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}

cplx cplx::operator-(cplx c) {
	cplx temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}

cplx cplx::operator*(cplx c) {
	cplx temp;
	temp.real = real * c.real - imag * c.imag;
	temp.imag = imag * c.real + c.imag * real;
	return temp;
}

cplx cplx::operator/(cplx c) {
	cplx temp;
	temp.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
	temp.imag = (imag*c.real - real*c.imag) / (c.real * c.real + c.imag * c.imag);
	return temp;
}

bool cplx::operator==(cplx c) {
	return abs(real - c.real) < epsilon && abs(imag - c.imag) < epsilon;
}

cplx cplx::operator=(cplx c)
{
	real = c.real;
	imag = c.imag;
	return c;
}

double cplx::get_r()
{
	return sqrt(real * real + imag * imag);
}

double cplx::get_fi()
{
	double fi;
	if (imag == 0 && real == 0) {
		fi = 0;
	} 
	else if (imag >= 0 && real > 0) {
		fi = atan(imag / real);
	}
	else if (imag < 0 && real > 0) {
		fi = atan(imag / real) + 2*M_PI;
	}
	else if (real < 0) {
		fi = atan(imag / real) + M_PI;
	}
	else if (imag > 0 && real == 0) {
		fi = M_PI_2;
	}
	else if (imag < 0 && real == 0) {
		fi = 3 * M_PI_2;
	}


	return fi;
}

ostream& operator<<(ostream& os, const cplx c)
{

	if (c.cplx_abs() < cplx::epsilon) {
		os << 0;
	}

	if (abs(c.real) > cplx::epsilon) {
		os << c.real;
		if (c.imag > cplx::epsilon) {
			os << '+';
		}
	}
	
	if (abs(c.imag) < cplx::epsilon) { // rounds small numbers (computing errors) to zero
		return os;
	}
	if (c.imag < 0) {
		os << '-';
	}
	double imag_abs = abs(c.imag);

	if (imag_abs != 1) {
		os << imag_abs;
	}
	os << 'i';
	return os;
}

bool cmp(cplx a, cplx b) {
	return (a - b).cplx_abs() < cplx::epsilon;
}
