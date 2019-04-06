#include "Vector.h"
#include<math.h>
#define PI 3.14159265
Vector::Vector()
{
}
//////�S�B�z0
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

double Vector::norm() const
{
	double mag = 0.0;
	for (unsigned int i = 0;i < this->Data.size();i++)
	{
		mag += pow(this->Data[i], 2);
	}
	mag = sqrt(mag);
	return mag;
}

Vector Vector::normal()
{
	Vector result;
	for (unsigned int i = 0;i < this->Data.size();i++)
	{
		result.Data.push_back(this->Data[i] / this->norm());
	}
	return result;
}

Vector cross(const Vector& A, const Vector& B)
{
	// �P�_�O�_�i�H�D cross --> ���ץ�����3
	// �Ψ䤤�@�謰 0 --> ���G��0
	if (A.Data.size() != 3 || B.Data.size() != 3 )
	{
		if ((A.Data.size() == 1 && A.Data[0] == 0) || (B.Data.size() == 1 && B.Data[0] == 0)) {}
		else
		{
			throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
		}
	}
	Vector result;
	if (A.Data.size() == 1 || B.Data.size() == 1)
	{
		result.Data.push_back(0);
	}
	else
	{
		double temp = 0.0;
		temp = A.Data[1] * B.Data[2] - A.Data[2] * B.Data[1];//i
		result.Data.push_back(temp);
		temp = 0.0;
		temp = A.Data[0] * B.Data[2] - A.Data[2] * B.Data[0];//j
		temp *= -1;
		result.Data.push_back(temp);
		temp = 0.0;
		temp = A.Data[0] * B.Data[1] - A.Data[1] * B.Data[0];//k
		result.Data.push_back(temp);
	}

	return result;
}

double com(const Vector& A,const Vector& B)//comp=(A dot B)/ ||B||
{
	// �P�_�O�_�i�H�p��comp --> ���ץ����ۦP
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double comp = 0.0, mag=0.0;//magnitude
	
	for (unsigned int i = 0; i < A.Data.size(); ++i)
	{
		comp += A.Data[i] * B.Data[i];
	}
	
	comp /= B.norm();
	return comp;
}

Vector proj(const Vector& A, const Vector& B)
{
	// �P�_�O�_�i�H�p��proj --> ���ץ����ۦP
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0,mag=0.0;
	Vector result;
	for (unsigned int i = 0; i < A.Data.size(); ++i)
	{
		dot += A.Data[i] * B.Data[i];
		mag += pow(B.Data[i], 2);
	}
	dot /= mag;
	for (unsigned int i = 0;i < B.Data.size();i++)
	{
		result.Data.push_back(dot*B.Data[i]);
	}
	return result;
}

double area(const Vector& A, const Vector& B)//  area=1/2 || A cross B ||
{
	// �P�_�O�_�i�H�p��area(triangle) --> ���ץ�����3
	if (A.Data.size() != 3||B.Data.size()!=3)
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	Vector result;
	double temp = 0.0,area=0.0;
	
	result = cross(A, B);
	area = result.norm();
	area /= 2;
	return area;
}

bool isparallel(const Vector& A, const Vector& B)
{

	// �P�_�O�_�i�H�D cross --> ���ץ�����3
	if (A.Data.size() != B.Data.size() )
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	else
	{
		double sclar = 0.0;
		bool isparallel = true;
		for (unsigned int i = 0;i < A.Data.size();i++)
		{
			if (A.Data[i] != 0 && B.Data[i] != 0)
			{
				if (sclar == 0)
				{
					sclar = A.Data[i] / B.Data[i];
				}
				else
				{
					if (sclar != A.Data[i] / B.Data[i])
					{
						return false;
					}
				}
			}
			else
			{
				if (A.Data[i] != B.Data[i])
				{
					return false;
				}
			}
		}
		return isparallel;

	}
}

bool isorthogonal(const Vector& A, const Vector& B)
{
	// �P�_�O�_���� --> ���ץ����ۦP   //����-->dot=0
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0;
	for (unsigned int i = 0;i < A.Data.size();i++)
	{
		dot += A.Data[i] * B.Data[i];
	}
	if (dot == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double angle(const Vector& A, const Vector& B)
{
	// �Dangle --> ���ץ����ۦP
	if (A.Data.size() != B.Data.size())
	{
		throw VECTOR_ERROR::DIMENSION_NON_EQUIVALENT;
	}
	double dot = 0.0, normA = 0.0,normB=0.0;//A dot B =||A|| ||B|| cos-->�ϱ��D����
	for (unsigned int i = 0;i < A.Data.size();i++)
	{
		dot += A.Data[i] * B.Data[i];
		normA += pow(A.Data[i], 2);
		normB += pow(B.Data[i], 2);
	}
	normA = sqrt(normA);
	normB = sqrt(normB);
	
	dot = dot / (normA*normB);//arc cos
	dot = acos(dot);//angle(����)
	dot = dot * 180 / PI;//angle(degree)
	return dot;
}

Vector pn(const Vector& A, const Vector& B)
{
	return cross(A,B);
}


std::vector<Vector> ob(std::vector<Vector> vectors)
{
	std::vector<Vector> result;
	Vector ans;
	for (unsigned int i = 0;i < vectors.size();i++)
	{
		ans = vectors[i];
		for (unsigned int j = 0;j < i;j++)
		{
			ans =ans-proj(vectors[i], result[j]);
		}

		
		result.push_back(ans.normal());
	}
	return result;
}
