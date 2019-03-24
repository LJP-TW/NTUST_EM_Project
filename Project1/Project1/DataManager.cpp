#include"DataManager.h"
#include <stack>

using System::String;
using namespace System::Collections::Generic;
using std::stack;

DataManager::DataManager()
{
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//���M�� Vectors �������
		this->Vectors.clear();

		//�V�q�`��
		unsigned int n;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�q�ɮ�Ū���r��A�ѪR�V�q�`��
		fin >> n;
		
		for (unsigned int i = 0; i < n; ++i)
		{
			//�w�q�Ȧs�V�q��Ƶ��c
			Vector tempVector;
			int dimension;

			//�ѪR���V�q�аO"V"
			fin >> tempSring;
			//�q�ɮ�Ū���r��A�ѪR�V�q����
			fin >> dimension;

			//�w�q�V�q�ܼƦW�١A��Ū�J���ǧ@�W�٪�����
			std::string vectorVariableTemp = "$v" + std::to_string(i);
			tempVector.Name = vectorVariableTemp;

			//Ū���V�q���
			for (unsigned int j = 0; j < dimension; ++j)
			{
				double value;
				fin >> value;
				tempVector.Data.push_back(value);
			}

			Vectors.push_back(tempVector);
		}

		//Ū�����\�^��true
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

Vector DataManager::VectorCalculate(String^ command)
{
	List<String^> postfix;
	Stack<String^> ops;
	stack<Vector> result;

	//�Ncommand�̪ťդ���
	array<String^> ^userCommand = command->Split(' ');

	//�Ʀ���Ǫk
	for (unsigned int i = 0; i < userCommand->Length; ++i)
	{
		if (userCommand[i] == gcnew String("(") || userCommand[i] == gcnew String("*"))
		{
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String("+"))
		{
			while (ops.Count != 0 && ops.Peek() == gcnew String("*"))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String(")"))
		{
			while (ops.Count != 0 && ops.Peek() != gcnew String("("))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Pop();
		}
		else
		{
			postfix.Add(userCommand[i]);
		}
	}
	while (ops.Count != 0)
	{
		postfix.Add(ops.Peek());
		ops.Pop();
	}

	//�B���Ǫk
	try 
	{
		for (unsigned int i = 0; i < postfix.Count; ++i)
		{
			unsigned int action = 0;
			if (postfix[i] == gcnew String("+"))
			{
				action = 1;
			}
			else if (postfix[i] == gcnew String("-"))
			{
				action = 2;
			}
			else if (postfix[i] == gcnew String("*"))
			{
				action = 3;
			}
			else
			{
				// �N�� postfix[i] �O Vector �W��
				// �M������ܼ� ��i stack result
				for (unsigned int j = 0; j < Vectors.size(); ++j)
				{
					if (postfix[i] == gcnew String(Vectors[j].Name.c_str()))
					{
						result.push(Vectors[j]);
						break;
					}
				}
				continue;
			}

			Vector temp = result.top();
			result.pop();
			switch (action)
			{
			case 1:
				result.top() = result.top() + temp;
				break;
			case 2:
				result.top() = result.top() - temp;
				break;
			case 3:
				result.top() = result.top() * temp;
				break;
			default:
				break;
			}
		}
	}
	catch (...)
	{
		throw;
	}
	
	return result.top();
}

bool DataManager::LoadMatrixData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//���M�� Matrices �������
		this->Matrices.clear();

		//�x�}�`��
		unsigned int n;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempSring;
		//�q�ɮ�Ū���r��A�ѪR�x�}�`��
		fin >> n;

		for (unsigned int i = 0; i < n; ++i)
		{
			//�w�q�Ȧs�x�}��Ƶ��c
			Matrix tempMatrix;
			int row_dimension, col_dimension;

			//�ѪR���x�}�аO"M"
			fin >> tempSring;
			//�q�ɮ�Ū���r��A�ѪR����
			fin >> row_dimension >> col_dimension;

			//�w�q�V�q�ܼƦW�١A��Ū�J���ǧ@�W�٪�����
			std::string matrixVariableTemp = "$m" + std::to_string(i);
			tempMatrix.Name = matrixVariableTemp;

			//Ū���x�}���
			for (unsigned int y = 0; y < row_dimension; ++y)
			{
				// �w�q�Ȧs row vector
				std::vector<double> rowVectorTemp;
				for (unsigned int x = 0; x < col_dimension; ++x)
				{
					double value;
					fin >> value;
					rowVectorTemp.push_back(value);
				}
				tempMatrix.Data.push_back(rowVectorTemp);
			}

			Matrices.push_back(tempMatrix);
		}

		//Ū�����\�^��true
		return true;
	}
}

std::vector<Matrix> DataManager::GetMatrices()
{
	return Matrices;
}

Matrix DataManager::MatrixCalculate(System::String ^ command)
{
	List<String^> postfix;
	Stack<String^> ops;
	stack<Matrix> result;

	//�Ncommand�̪ťդ���
	array<String^> ^userCommand = command->Split(' ');

	//�Ʀ���Ǫk
	// Priority:
	// [*] -> [+, -] -> [/]
	for (unsigned int i = 0; i < userCommand->Length; ++i)
	{
		if (userCommand[i] == gcnew String("(") || userCommand[i] == gcnew String("*"))
		{
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String("+") || userCommand[i] == gcnew String("-"))
		{
			while (ops.Count != 0 && ops.Peek() == gcnew String("*"))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String("/"))
		{
			while (ops.Count != 0 \
				&& (ops.Peek() == gcnew String("*") || \
					ops.Peek() == gcnew String("+") || \
					ops.Peek() == gcnew String("-")))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Push(userCommand[i]);
		}
		else if (userCommand[i] == gcnew String(")"))
		{
			while (ops.Count != 0 && ops.Peek() != gcnew String("("))
			{
				postfix.Add(ops.Peek());
				ops.Pop();
			}
			ops.Pop();
		}
		else
		{
			postfix.Add(userCommand[i]);
		}
	}
	while (ops.Count != 0)
	{
		postfix.Add(ops.Peek());
		ops.Pop();
	}

	//�B���Ǫk
	try
	{
		for (unsigned int i = 0; i < postfix.Count; ++i)
		{
			unsigned int action = 0;
			if (postfix[i] == gcnew String("+"))
			{
				action = 1;
			}
			else if (postfix[i] == gcnew String("-"))
			{
				action = 2;
			}
			else if (postfix[i] == gcnew String("*"))
			{
				action = 3;
			}
			else if (postfix[i] == gcnew String("/"))
			{
				action = 4;
			}
			else
			{
				// �N�� postfix[i] �O Vector �W��
				// �M������ܼ� ��i stack result
				for (unsigned int j = 0; j < Matrices.size(); ++j)
				{
					if (postfix[i] == gcnew String(Matrices[j].Name.c_str()))
					{
						result.push(Matrices[j]);
						break;
					}
				}
				continue;
			}

			Matrix temp = result.top();
			result.pop();
			switch (action)
			{
			case 1:
				result.top() = result.top() + temp;
				break;
			case 2:
				result.top() = result.top() - temp;
				break;
			case 3:
				result.top() = result.top() * temp;
				break;
			case 4:
				result.top() = result.top() / temp;
				break;
			default:
				break;
			}
		}
	}
	catch (...)
	{
		throw;
	}

	return result.top();
}

