/*
 * Matrix.h
 *
 *  Created on: 07.11.2015
 *      Author: stefan
 */

#ifndef MATRIX_H_
#define MATRIX_H_

/**
 * A class that represents a square matrix. It offers basic mathematical operations on that matrix.
 */
class Matrix
{
public:
	Matrix();
	Matrix(int size, int** matrix);
	virtual ~Matrix();

	void setSize(int size);
	void setValue(int value, int i, int j);
	void setMatrix(int** matrix, int size);

	int getSize();
	int getValue(int i, int j);
	int** getMatrix();
	Matrix* multiply(Matrix& matrix);
	void setMatrix(int size, int** matrix);

	int* operator[](int);

private:
	int** _matrix;
	int _size;
	int** initMatrix(int size);
};

#endif /* MATRIX_H_ */
