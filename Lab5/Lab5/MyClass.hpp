#include <iostream>
#include <math.h>
#include "MyClass.h"

template<typename T>
MyClass<T>::MyClass(T a)
{
	this->a = a;
}

template <typename T>
float MyClass<T>::square(T Power)
{
	return pow(this->a, Power);
}

template<typename T>
float MyClass<T>::multiply(T fact)
{
	return this->a * fact;
}

template<typename T>
float MyClass<T>::divide(T divider)
{
	return this->a / divider;
}