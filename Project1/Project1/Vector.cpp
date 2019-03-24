#include "Vector.h"

Vector::Vector()
{
}

Vector Vector::operator+(const Vector & v)
{
	// �P�_�O�_�i�H�ۥ[ --> ���ץ����ۦP
	if (this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result = *this;
	
	for (unsigned int i = 0; i < result.Data.size(); ++i)
	{
		result.Data[i] += v.Data[i];
	}

	return result;
}

Vector Vector::operator-(const Vector & v)
{
	// �P�_�O�_�i�H�۴� --> ���ץ����ۦP
	if (this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result = *this;

	for (unsigned int i = 0; i < result.Data.size(); ++i)
	{
		result.Data[i] -= v.Data[i];
	}

	return result;
}

Vector Vector::operator*(const Vector & v)
{
	// �P�_�O�_�i�H�D dot --> ���ץ����ۦP
	// �Ψ䤤�@�謰 scalar --> �䤤�@����ץ������� 1
	if (this->Data.size() != 1 && v.Data.size() != 1 && this->Data.size() != v.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}

	Vector result;

	if (this->Data.size() == 1)
	{
		result = v;

		for (unsigned int i = 0; i < result.Data.size(); ++i)
		{
			result.Data[i] *= this->Data[0];
		}
		
	}
	else if (v.Data.size() == 1)
	{
		result = *this;

		for (unsigned int i = 0; i < result.Data.size(); ++i)
		{
			result.Data[i] *= v.Data[0];
		}
	}
	else
	{
		double dot = 0;

		for (unsigned int i = 0; i < this->Data.size(); ++i)
		{
			dot += this->Data[i] * v.Data[i];
		}

		result.Data.push_back(dot);
	}

	return result;
}

double Vector::norm()
{
	return 0.0;
}

double Vector::normal()
{
	return 0.0;
}

Vector cross(const Vector& A, const Vector& B)
{
	return Vector();
}

double com(const Vector& A, const Vector& B)
{
	return 0.0;
}

Vector proj(const Vector& A, const Vector& B)
{
	return Vector();
}

double area(const Vector& A, const Vector& B)
{
	return 0.0;
}

bool isparallel(const Vector& A, const Vector& B)
{
	return false;
}

bool isorthogonal(const Vector& A, const Vector& B)
{
	return false;
}

double angle(const Vector& A, const Vector& B)
{
	return 0.0;
}

Vector pn(const Vector& A, const Vector& B)
{
	return Vector();
}

bool isln(const Vector& A, const Vector& B)
{
	return false;
}

std::vector<Vector> ob(std::vector<Vector> vectors)
{
	return std::vector<Vector>();
}
