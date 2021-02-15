#include "MyClass.h"


MyClass::MyClass(int Size)				//Конструктор
{
	this->Size = Size;
	this->data = new int[Size];

	for (int i = 0; i < Size; i++)
	{
		data[i] = i+1;
	}
}

MyClass::MyClass(const MyClass& other)	//Коструктор копирования
{
	this->Size = other.Size;
	this->data = new int[other.Size];

	for (int i = 0; i < Size; i++)
	{
		this->data[i] = other.data[i];
	}
}

MyClass::~MyClass()						//Деструктор
{
	delete[] data;
}

void MyClass::Show()					//Вывод объекта на экран
{
	for (int i = 0; i < this->Size; i++)
		cout << data[i] << " ";
	cout << endl;
}

MyClass & MyClass::operator = (const MyClass& other)	//Перегрузка оператора присваивания
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

bool MyClass::operator == (const MyClass& other)		//Перегрузка опреатора сравнения
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

MyClass& MyClass::operator - ()							//Перегрузка оператора смены знака
{
	for (int i = 0; i < this->Size; i++)
		this->data[i] = -(this->data[i]);
	return *this;
}