#pragma once
#include "Vector.h"
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
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	//�B��V�q���
	Vector Calculate(System::String^ command);
};