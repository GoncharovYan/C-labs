#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	void SetWeight(int weight) { this->weight = weight; }
	int GetWeight() { return weight; }
protected:
	void infoA()
	{
		string AnType;
		if (type == 1) { AnType = "beaver"; }
		else if (type == 2) { AnType = "lion"; }
		else if (type == 3) { AnType = "kangoroo"; }
		string AnPred;
		if (predator) { AnPred = "predator"; }
		else { AnPred = "not a predator"; }

		cout << endl << "It's a " << AnType << ", who have " << legs << " legs and weighs " << weight << "kg, by the way, he is " << AnPred << endl;
	}

	int weight;
	int legs;
	bool predator;
	int type;
};
/// ///////////////
class Beaver : public Animal
{
public:
	Beaver(int weight, int Tooth_length)
	{
		SetWeight(weight);
		this->Tooth_length = Tooth_length;
		legs = 4;
		type = 1;
		predator = false;
	}
	void info()
	{
		infoA();
		cout << "The length of his teeth is "<< Tooth_length << " centimeters" << endl;
	}

	void Gnaw_a_tree()
	{
		if (Tooth_length >= 2) { Tooth_length--; }
		else Tooth_length = 1;
		cout << "Beaver gnaw a tree. His teeth are now " << Tooth_length << " centimeters long"<< endl;
	}
	void Try_To_Jump()
	{
		cout << "Beavers can't jump..." << endl;
	}
private:
	int Tooth_length;
};
class Lion : public Animal
{
public:
	Lion(int weight, int V)
	{
		this->V = V;
		this->weight = weight;
		legs = 4;
		predator = true;
		type = 2;
	}
	
	void ShakeMane()
	{
		cout << "Lion shake his mane\n";
	}

	void info()
	{
		infoA();
		cout << "Volume of his mane is " << V << endl;
	}

	void Jump()
	{
		cout << "Leo can jump and he does it." << endl;
	}

private:
	int V;
};
class Kangoroo : public Animal
{
public:
	Kangoroo(int weight, int Kangaroos_in_a_bag)
	{
		this->weight = weight;
		this->Kangaroos_in_a_bag = Kangaroos_in_a_bag;
		legs = 2;
		predator = false;
		type = 3;
	}
	void info()
	{
		infoA();
		cout << "She has " << Kangaroos_in_a_bag << " kangoroos in a bag" << endl;
	}
	void Jump()
	{
		Kangaroos_in_a_bag--;
		cout << "The kangaroo jumped, but dropped one kangaroo from her bag. Now she has " << Kangaroos_in_a_bag << " kangaroos in her bag" << endl;
	}

private:
	int Kangaroos_in_a_bag;
};

int main()
{
	Beaver Dread(20,5);
	Dread.info();
	Dread.Gnaw_a_tree();
	Dread.Try_To_Jump();
	Dread.info();

	Lion Frank(180, 20);
	Frank.info();
	Frank.Jump();
	Frank.ShakeMane();

	Kangoroo Bodya(60, 3);
	Bodya.info();
	Bodya.Jump();
	Bodya.GetWeight();
	Bodya.info();

	return 0;
}