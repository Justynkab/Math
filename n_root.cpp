#include "n_root.h"
#define _USE_MATH_DEFINES
#include "math.h"

cplx n_root_k(double p, double fi, int n, int k) {
    double psi = (fi + 2 * k * M_PI) / n;
    return cplx(p * cos(psi), p * sin(psi));
}

void n_root(cplx result[], double x, int n) {
    double r = abs(x);
    double fi;

    if (x >= 0) {
        fi = 0;
    }
    else {
        fi = M_PI;
    }
    double p = pow(r, 1. / n);
    for (int k = 0; k < n; k++) {
        result[k] = n_root_k(p, fi, n, k);
    }
}

void n_root(cplx result[], cplx z, int n) {
    double r = z.get_r();
    double fi = z.get_fi();
    if (r == 0) {
        for (int i = 0; i < n; i++) {
            result[i] = cplx(0);
        }
        return;
    }     
    
    double p = pow(r, 1. / n);
    for (int k = 0; k < n; k++) {
        result[k] = n_root_k(p, fi, n, k);
    }
}

cplx power_n(cplx x, int n) {
    cplx product(1, 0);
    for (int j = 0; j < n; j++) {
        product = product * x;
    }
    return product;
}

cplx power_2(cplx x) {
    return power_n(x, 2);
}

cplx power_3(cplx x) {
    return power_n(x, 3);
}

cplx power_4(cplx x) {
    return power_n(x, 4);
}