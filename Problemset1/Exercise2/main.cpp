#include <iostream>
#include <omp.h>
#include "Matrix.h"

using namespace std;

void fill(int size, int** a, int** b);

int main()
{
	int size = 100;
	int** a;
	int** b;

	a = new int*[size];
	b = new int*[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
		b[i] = new int[size];
	}

	fill(size,a,b);

	Matrix& A = *new Matrix(size,a);

	cout << A[1][2] << endl;

	return 0;
}

void fill(int size, int** a, int** b)
{
	for(int i = 0; i < size; i++)
	{
		int j;
		for(j = 0; j < i; j++)
		{
			a[i][j] = 5;
			b[i][j] = 3;
		}

		a[i][j] = 2;
		b[i][j] = 1;

		for(j++; j < size; j++)
		{
			a[i][j] = 4;
			b[i][j] = 6;
		}
	}
}
