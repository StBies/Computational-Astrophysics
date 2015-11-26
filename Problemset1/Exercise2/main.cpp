#include <iostream>
#include <omp.h>
#include "Matrix.h"

using namespace std;

void fill(int size, int** a, int** b);


/**
 * Program to multiply two square matrices and compare the computation time of that process for
 * automatic compiler vectorization and openMP parallelization.
 */
int main()
{
	int size = 4000;
	int** a;
	int** b;

	a = new int*[size];
	b = new int*[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
		b[i] = new int[size];
	}

	fill(size, a, b);

	Matrix* A = new Matrix(size, a);
	Matrix* B = new Matrix(size, b);
	Matrix* C = A->multiply(*B);

//	cout << C->getValue(1,1) << endl;

	delete A;
	delete B;
	delete C;

	return 0;
}

/**
 * Fills the values given in the problemset into the given 2D arrays.
 * Is faster than index checks in the loops.
 *
 * @author Stefan
 * @date Nov. 9, 2015
 *
 * @version 0.9
 *
 * @param size The size of the arrays to be filled
 * @param a First 2D array to be filled
 * @param b Second 2D array to be filled.
 */
void fill(int size, int** a, int** b)
{
	for (int i = 0; i < size; i++)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			a[i][j] = 5;
			b[i][j] = 3;
		}

		a[i][j] = 2;
		b[i][j] = 1;

		for (j++; j < size; j++)
		{
			a[i][j] = 4;
			b[i][j] = 6;
		}
	}
}
