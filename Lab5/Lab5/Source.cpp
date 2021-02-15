#include <iostream>
#include <math.h>
#include "MyClass.h"
#include "MyClass.hpp"
using namespace std;

int main()
{
	MyClass<int> a(10);

	cout << a.multiply(2) << endl;

	cout << a.square(2) << endl;

	cout << a.divide(2) << endl;
	
	cout << endl;
	MyClass<float> b(2.5);

	cout << b.multiply(2) << endl;

	cout << b.square(2) << endl;

	cout << b.divide(2) << endl;

	return 0;
}