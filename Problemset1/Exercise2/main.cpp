#include <iostream>
#include <omp.h>
#include "Matrix.h"

using namespace std;

void fill(int size, int** a, int** b);

int** multiply(int size, int** a, int** b);

int main()
{
	int size = 200;
	int** a;
	int** b;
	int** c;

	a = new int*[size];
	b = new int*[size];
	c = new int*[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
		b[i] = new int[size];
		c[i] = new int[size];
	}

	fill(size, a, b);

	Matrix* A = new Matrix(size, a);
	Matrix* B = new Matrix(size, b);
	Matrix* C = A->multiply(*B);


	cout << C->getValue(1,1) << endl;

	delete A;
	delete B;
	delete C;

	return 0;
}

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

int** multiply(int size, int** a, int** b)
{
	int** result;
	result = new int*[size];

	for (int i = 0; i < size; i++)
	{
		result[i] = new int[size];
	}

	double startTime;
	double endTime;
	startTime = omp_get_wtime();
	int stepresult = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			for (int k = 0; k < size; k++)
			{

				stepresult += a[i][k] * b[k][j];
			}
			result[i][j] = stepresult;
			stepresult = 0;
		}
	}
	endTime = omp_get_wtime();

	cout << 1000 * (endTime - startTime) << endl;

	return result;
}
