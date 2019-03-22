#pragma once
#include <iostream>
#include <vector>

//�w�q�V�q��Ƶ��c
class Vector
{
public:
	std::string Name;
	std::vector<double> Data;

	Vector() {};

	Vector operator +(const Vector& v);
	Vector operator *(const Vector& v);
	double norm();
	double normal();
	friend Vector cross(Vector& A, Vector& B);
	friend double com(Vector& A, Vector& B);
	friend Vector proj(Vector& A, Vector& B);
	friend double area(Vector& A, Vector& B);
	friend bool isparallel(Vector& A, Vector& B);
	friend bool isorthogonal(Vector& A, Vector& B);
	friend double angle(Vector& A, Vector& B);
	friend Vector pn(Vector& A, Vector& B);
	friend bool isln(Vector& A, Vector& B);
	friend std::vector<Vector> ob(std::vector<Vector> vectors);
};

// �w�q�������~
enum class VECTOR_ERROR {
	DIMENSION_NON_EQUIVALENT
};