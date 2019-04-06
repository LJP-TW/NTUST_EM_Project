#pragma once
#include "Vector.h"
#include "Matrix.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�x�s�x�}���
	std::vector<Matrix> Matrices;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	//�B��V�q���
	Vector VectorCalculate(System::String^ command);
	//Ū���x�}���
	bool LoadMatrixData();
	//���o�x�}���
	std::vector<Matrix> GetMatrices();
	//�B��x�}���
	Matrix MatrixCalculate(System::String^ command);
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};

// �w�q�������~
enum class DATA_MANAGER_ERROR {
	VARIABLE_NOT_FOUND // �䤣���ܼ�
};