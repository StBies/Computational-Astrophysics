/*
 * Matrix.cpp
 *
 *  Created on: 07.11.2015
 *      Author: stefan
 */

#include "Matrix.h"
#include <iostream>

/**
 * Default constructor. Initializes an empty square matrix of size 2.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 */
Matrix::Matrix()
{
	_size = 2;
	_matrix = initMatrix(_size);
}

/**
 * Constructor. Builds a new Matrix of given size and containing a matrix given a twodimensional array.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param size The size of the matrix. Must correspont with the size of the 2D square array matrix.
 * @param matrix The 2D square array you want the Matrix to contain.
 */
Matrix::Matrix(int size, int** matrix)
{
	_size = size;
	_matrix = matrix;
}

/**
 * Clears the heap from this matrix.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 */
Matrix::~Matrix()
{
	delete[] _matrix;
	delete this;
}

/**
 * Sets the size of the matrix
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param size The new size of the matrix. Matrix itself is not affected.
 */
void Matrix::setSize(int size)
{
	_size = size;
}

/**
 * Sets a specific value of the matrix.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param value The value, that is to be set
 * @param i The row at which the value is to be set
 * @param j The column at which the value is to be set
 *
 * @version 0.1
 */
void Matrix::setValue(int value, int i, int j)
{
	if (i < _size && j < _size)
	{
		_matrix[i][j] = value;
	}
}

/**
 * Read the size of the square matrix
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @return The size of the matrix.
 */
int Matrix::getSize()
{
	return _size;
}

/**
 * Returns the matrix as a double pointer array of integers.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @return an array of pointers to integer-arrays containing the matrix.
 */
int** Matrix::getMatrix()
{
	return _matrix;
}

/**
 * Returns the integer value of the matrix at position row, column
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param i The row, that you want the value in
 * @param j The column, that you want the value in
 *
 * @return The value at position i,j
 */
int Matrix::getValue(int i, int j)
{
	try
	{
		if (i < _size && j < _size)
		{
			return _matrix[i][j];
		}
		else
		{
			throw 'i';
		}
	} catch (char c)
	{
		if (c == 'i')
		{
			std::cout << "Index out of bounds. You wanted: " << i << ", " << j
					<< ". Size is: " << _size << std::endl;
			std::cout << "Returned -42 instead of real result" << std::endl;
		}
		return -42;
	}
}

/**
 * Setup the matrix to contain a given twodimensional array. Better use the corresponding constructor to build a new
 * Matrix-object to avoid confusion.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param size The size of the twodimensional square array
 * @param matrix the twodimensional square array, you want the matrix to hold
 */
void Matrix::setMatrix(int size, int** matrix)
{
	_size = size;
	_matrix = matrix;
}

int** Matrix::initMatrix(int size)
{
	int ** result = new int*[size];

	for (int i = 0; i < size; i++)
	{
		result[i] = new int[size];
	}

	return result;
}


/**
 * Multiply this Matrix with another Matrix. If the dimensions don't allow multiplication, an exception will be thrown.
 * The calling Matrix object is the left hand side operand of the multiplication.
 * Works for square matrices only.
 *
 * @author Stefan Bieschke
 * @date Nov. 7, 2015
 *
 * @param matrix The matrix at the right side of the multiplication.
 *
 * @return The resulting matrix of the multiplication.
 */
Matrix* Matrix::multiply(Matrix& matrix)
{
	int** result;

	if(matrix.getSize() == _size)
	{
		result = initMatrix(_size);
	}

	return new Matrix(_size, result);
}

int* Matrix::operator[](int row)
{
	return _matrix[row];
}
