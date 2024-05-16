#include "n_root.h"
#include <cassert>

void test_n_root(double x, int n) {
    cplx* result = new cplx[n];
    n_root(result, x, n);
    for (int i = 0; i < n; i++) {
        cplx product = power_n(result[i], n);
        cout << "sprawdzenie dla " << result[i] << ": " << product << endl;
        assert(abs(product.real - x) <= cplx::epsilon);
        assert(abs(product.imag) <= cplx::epsilon);
    }
    delete result;
}

void test_n_root(cplx z, int n) {
    cplx* result = new cplx[n];
    n_root(result, z, n);
    for (int i = 0; i < n; i++) {
        cplx product = power_n(result[i], n);
        cout << "sprawdzenie dla " << result[i] << ": " << product << endl;
        assert(abs(product.real - z.real) <= cplx::epsilon);
        assert(abs(product.imag - z.imag) <= cplx::epsilon);
    }
    delete result;
}