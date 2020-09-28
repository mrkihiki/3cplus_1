// lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct datetime {
	int day = 0;
	int month = 0;
	int year = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
};

struct timedelta {
	int day = 0;
	int month = 0;
	int year = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
};
void mus(datetime, timedelta);
void out(timedelta* Arr2, int ll);
int main()
{

	setlocale(LC_ALL, "rus");

	string x;
	datetime s;
	ifstream vod;

	vod.open("1.txt");
	int l = 0;

	if (vod.is_open()) {
		while (!vod.eof()) {
			string s;
			getline(vod, s);
			l++;
		}
	}
	datetime* Arr = new datetime[l];
	vod.seekg(0, ios_base::beg);//начало файла

	for (size_t i = 0; i < l; i++)
	{
		getline(vod, x);
		istringstream iss(x);//поток ввода
		iss >> s.day >> s.month >> s.year >> s.seconds >> s.minutes >> s.hours;
		Arr[i] = s;

	}
	vod.close();
	//////////////////////////////////////////////////
	string xx;
	timedelta ss;

	vod.open("11.txt");
	int ll = 0;

	if (vod.is_open()) {
		while (!vod.eof()) {
			string ss;
			getline(vod, ss);
			ll++;
		}
	}
	timedelta* Arr2 = new timedelta[ll];
	vod.seekg(0, ios_base::beg);//начало файла

	for (size_t i = 0; i < ll; i++)
	{
		getline(vod, xx);
		istringstream iss(xx);//поток ввода
		iss >> ss.day >> ss.month >> ss.year >> ss.seconds >> ss.minutes >> ss.hours;
		Arr2[i] = ss;

	}


	cout << "Все квартиры: \n" << endl;

	for (size_t n = 0; n < l; n++)
	{
		cout << "day : " << Arr[n].day << " "
			<< "month : " << Arr[n].month << " "
			<< "year : " << Arr[n].year << " "
			<< "seconds : " << Arr[n].seconds << " "
			<< "minutes : " << Arr[n].minutes << " "
			<< "hours : " << Arr[n].hours << endl;
	}
	cout << "Все квартиры: \n" << endl;

	for (size_t n = 0; n < ll; n++)
	{
		cout << "day : " << Arr2[n].day << " "
			<< "month : " << Arr2[n].month << " "
			<< "year : " << Arr2[n].year << " "
			<< "seconds : " << Arr2[n].seconds << " "
			<< "minutes : " << Arr2[n].minutes << " "
			<< "hours : " << Arr2[n].hours << endl;
	}

	////////////////////////////////////////////////////////////////////////////////

	out(Arr2[0], ll);
}

void out(timedelta* Arr2, int ll)
{
	for (size_t n = 0; n < ll; n++)
	{
		cout << "day : " << Arr2[n].day << " "
			<< "month : " << Arr2[n].month << " "
			<< "year : " << Arr2[n].year << " "
			<< "seconds : " << Arr2[n].seconds << " "
			<< "minutes : " << Arr2[n].minutes << " "
			<< "hours : " << Arr2[n].hours << endl;
	}
}
void mus(datetime, timedelta)
{




}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
