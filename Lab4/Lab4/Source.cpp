#include <iostream>
#include "MyClass.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");

	MyClass a(5);
	MyClass b(10);
	MyClass c(15);

	a.Show();
	b.Show();
	c.Show();

	cout << endl;
	cout << (a == b) << endl;
	cout << endl;

	a = b = c;

	a.Show();
	b.Show();
	c.Show();

	cout << endl;
	cout << (a == b) << endl;
	cout << endl;

	a = -b;
	a.Show();

	return 0;
}