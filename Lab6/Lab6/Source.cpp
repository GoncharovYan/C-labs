#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

void CycleSum(int s, int e, int arr[], int& SUM)
{
	for (int i = s; i < e; i++)
		SUM = SUM + arr[i];
}

void ArrSum(int s, int arr[], int &SUM)
{
	int part = s / 4;
	int part1 = part * 2;
	int part2 = part * 3;

	thread t1(CycleSum, 0, part, arr, std::ref(SUM));
	thread t2(CycleSum, part, part1, arr, std::ref(SUM));
	thread t3(CycleSum, part1, part2, arr, std::ref(SUM));
	thread t4(CycleSum, part2, s, arr, std::ref(SUM));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

void Dowork1(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "����� 1: " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

void Dowork2(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "����� 2: " << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(505));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

/// ////// //////// ///////// (1/3) ////// ///////// ////////
	cout << "1 �����" << endl << endl;

	thread th1(Dowork1,10);
	Dowork2(10);

	th1.join();


/// ////// //////// ///////// (2/3) ////// ///////// ////////
	cout << endl << "_________________________________________" << endl;
	cout << "2 �����" << endl << endl;

	unsigned int start = clock();
	Dowork1(10);
	Dowork2(10);
	unsigned int end = clock();
	cout << "����� ������ ��������� ��� ������������� ���������������: " << end - start << endl;

	start = clock();
	thread th11(Dowork1,10);
	Dowork2(10);
	end = clock();
	cout << "����� ������ ��������� � �������������� ���������������: " << end - start << endl;

	th11.join();


	start = clock();
	thread th21(Dowork1, 5);
	thread th22(Dowork1, 5);
	thread th23(Dowork2, 5);
	Dowork2(5);
	end = clock();
	cout << "����� ������ ��� ������������� ������ �������: " << end - start << endl;

	th21.join();
	th22.join();
	th23.join();

	/// ////// //////// ///////// (3/3) ////// ///////// ////////
	cout << endl << "_________________________________________" << endl;
	cout << "3 �����" << endl << endl;

	int SUM = 0;

	int arr[10000];
	for (int i = 0; i < 10000; i++)
		arr[i] = rand() % 10;

	start = clock();
	ArrSum(10000, arr, SUM);
	end = clock();

	cout << "����� ������� �� 10 000 ��������� � �������������� 4-� ����� ���� ���������� ��: " << end - start << endl;
	cout << "����� �������: " << SUM << endl;

	return 0;
}