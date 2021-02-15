#pragma once
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int Size);
	MyClass(const MyClass& other);
	~MyClass();

	void Show();

	MyClass & operator = (const MyClass& other);
	bool operator == (const MyClass& other);
	MyClass& operator - ();
private:
	int Size;
	int *data;
};

