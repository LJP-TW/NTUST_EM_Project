#include"DataManager.h"
#include <stack>

using System::String;
using namespace System::Collections::Generic;
using std::stack;

DataManager::DataManager()
{
	VectorVariableIndex = 0;
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
		this->VectorVariableIndex = 0;

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

			//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
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

		//Ū�����\�^��false
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

Vector DataManager::Calculate(String^ command)
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
			if (postfix[i] == gcnew String("+"))
			{
				Vector temp = result.top();
				result.pop();
				result.top() = result.top() + temp;
			}
			else if (postfix[i] == gcnew String("*"))
			{
				Vector temp = result.top();
				result.pop();
				result.top() = result.top() * temp;
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
			}
		}
	}
	catch (...)
	{
		throw;
	}
	
	return result.top();
}

