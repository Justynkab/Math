#include "equation2.h"
#include "equation3.h"
#include "equation4.h"
#include "n_root.h"
#include "cplx.h"
#include <cassert>

//void resolvent()


void equation4(cplx result[4], double A, double B, double C, double D, double E)
{
	double p, q, r, n;
	n = B / (4 * A);
	p = 6 * n * n - 3 * B * n / A + C / A;
	q = -4 * n * n * n + 3 * n * n  * B / A - 2 * n * C / A + D / A;
	r = n * n * n * n - n * n * n * B / A + n * n * C / A - n * D / A + E / A;

	if (p == 0 && q == 0 && r == 0) {
		cout << "p == q == r == 0" << endl;
		for (int i = 0; i < 4; i++) {
			result[i] = -n;
		}
		return;
	} else if (p == 0 && q == 0) {
		cout << "p == q == 0" << endl;
		n_root(result, -r, 4);
		return;
	}
	else if (p * r != 0 && q == 0) {
		cout << "p * r != 0 && q == 0" << endl;
		cplx result2[2];
		equation2(result2, 1, p, r);
		int j = 0;
		for (int i = 0; i < 2; i++) {
			cplx temp[2];
			n_root(temp, result2[i], 2);
			result[j] = temp[0];
			result[j + 1] = temp[1];
			j = j + 2;
		}
		assert(j == 4);
	}

	cplx result3[3];
	equation3(result3, 1, 2 * p, p * p - 4 * r, -q * q);
	cplx result_uvw[3][2];
	for (int i = 0; i < 3; i++) {
		cplx z[2];
		n_root(z, result3[i], 2);
		result_uvw[i][0] = z[0];
		result_uvw[i][1] = z[1];
	}
	int h = 0;
	cplx result_z[4];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (cmp(result_uvw[0][i] * result_uvw[1][j] * result_uvw[2][k], cplx(-q))) {
					result_z[h] = (result_uvw[0][i] + result_uvw[1][j] + result_uvw[2][k]) * cplx(0.5);
					h++;
					if (h == 4) {
						i = 2;
						j = 2;
						k = 2;
					}
				}
			}
		}
	}

	assert(h == 4);
	
	for (int i = 0; i < 4; i++) {
		result[i] = result_z[i] - cplx(n);
	}

}