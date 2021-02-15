#pragma once
#include <iostream>
#include <math.h>

template <typename T>
class MyClass
{
private:
	T a;
public:
	MyClass(T a);

	float square(T Power);

	float multiply(T fact);

	float divide(T divider);
};
