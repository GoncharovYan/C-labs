#include "MyClass.h"


MyClass::MyClass(int Size)				//�����������
{
	this->Size = Size;
	this->data = new int[Size];

	for (int i = 0; i < Size; i++)
	{
		data[i] = i+1;
	}
}

MyClass::MyClass(const MyClass& other)	//���������� �����������
{
	this->Size = other.Size;
	this->data = new int[other.Size];

	for (int i = 0; i < Size; i++)
	{
		this->data[i] = other.data[i];
	}
}

MyClass::~MyClass()						//����������
{
	delete[] data;
}

void MyClass::Show()					//����� ������� �� �����
{
	for (int i = 0; i < this->Size; i++)
		cout << data[i] << " ";
	cout << endl;
}

MyClass & MyClass::operator = (const MyClass& other)	//���������� ��������� ������������
{
	this->Size = other.Size;
	delete[] this->data;

	this->data = new int[Size];

	for (int i = 0; i < other.Size; i++)
	{
		this->data[i] = other.data[i];
	}

	return *this;
}

bool MyClass::operator == (const MyClass& other)		//���������� ��������� ���������
{
	if (this->Size != other.Size) { return false; }
	else
	{
		for (int i = 0; i < this->Size; i++)
		{
			if (this->data[i] != other.data[i]) { return false; }
		}
	}

	return true;
}

MyClass& MyClass::operator - ()							//���������� ��������� ����� �����
{
	for (int i = 0; i < this->Size; i++)
		this->data[i] = -(this->data[i]);
	return *this;
}