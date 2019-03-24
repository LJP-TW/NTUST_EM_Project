#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix();

	std::string Name;
	std::vector<std::vector<double>> Data;

	/*
	 * Addition
	 * �i��| throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator +(const Matrix& m);

	/*
	 * Subtraction
	 * �i��| throw
	 * - DIMENSION_NON_EQUIVALENT
	 */
	Matrix operator -(const Matrix& m);

	/*
	 * Multiplication
	 * �i��| throw
	 * - MULTIPLICATION_DIMENSION_ERROR
	 */
	Matrix operator *(const Matrix& m);

	/*
	 * Solving linear system
	 */
	Matrix operator /(const Matrix& m);
};

// �w�q�������~
enum class MATRIX_ERROR {
	DIMENSION_NON_EQUIVALENT,
	MULTIPLICATION_DIMENSION_ERROR
};