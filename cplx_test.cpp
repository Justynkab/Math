#include "cplx.h"
#include <cassert>

void test_get_fi(cplx z, double fi) {
	cout << "testing: " << z << " == " << fi << endl;
	assert(abs(z.get_fi() - fi) < cplx::epsilon);
}