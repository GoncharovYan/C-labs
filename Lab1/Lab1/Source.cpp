#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
	string ColorOfTheHat;
	int Weight;
	int Height;
	int Age;
	bool Married;

public:
	Human(string ColorOfTheHat, int Age, int Weight, int Height)
	{
		this->ColorOfTheHat = ColorOfTheHat;
		this->Age = Age;
		this->Weight = Weight;
		this->Height = Height;
		this->Married = false;
	}

	void ChangeTheHat(string ColorOfTheHat) { this->ColorOfTheHat = ColorOfTheHat; }
	int GetAge() { return Age; }
	void SetAge(int Age) { this->Age = Age; }
	int GetWeight() { return Weight; }
	void SetWeight(int Weight) { this->Weight = Weight; }
	int GetHeight() { return Height; }
	void SetHeight(int Height) { this->Height = Height; }
	void info()
	{
		cout << "Color of the hat is " << ColorOfTheHat << "\nWeight is " << Weight << "\nHeight is " << Height << "\nAges " << Age << endl;
		if (Married)
			cout << "Married" << endl << endl;
		else
			cout << "Not married" << endl << endl;
	}
	void GetMarried() { Married = true; }
	void GetDivorce() { Married = false; }



};

int main()
{
	Human Andrey("green", 27, 88, 170);
	Andrey.GetMarried();
	Andrey.info();

	Andrey.SetWeight(102);
	Andrey.ChangeTheHat("gray checkered");
	Andrey.GetDivorce();
	Andrey.info();

	return 0;
}