// lab_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

int vess(int s);
int den(int s, int a, int g);
int pden(int s, int a, int g);

struct datetime {
	int day = 0;
	int month = 0;
	int year = 0;
	int seconds = 0;
	int minutes = 0;
	int hours = 0;
	void method(datetime*& Ar1r2, int l)
	{
		int a = -1;
		for (size_t n = 0; n < l; n++)
		{
			a = den(Ar1r2[n].month, Ar1r2[n].day, Ar1r2[n].year);
			if (a == 0) { Ar1r2[n].day += 1; }
			else { if (Ar1r2[n].month == 12) { Ar1r2[n].year += 1;  Ar1r2[n].day = 1; Ar1r2[n].month = 1; } else { Ar1r2[n].day = 1; Ar1r2[n].month += 1; } }
		}
	}
	void predd(datetime*& Ar2r2, int l)
	{
		int a = -1;
		for (size_t n = 0; n < l; n++)
		{
			a = pden(Ar2r2[n].month, Ar2r2[n].day, Ar2r2[n].year);
			if (Ar2r2[n].day != 1) { Ar2r2[n].day -= 1; }
			else { if (Ar2r2[n].month == 1) { Ar2r2[n].year -= 1;  Ar2r2[n].day = 31; Ar2r2[n].month = 12; } else { Ar2r2[n].day = a; Ar2r2[n].month -= 1; } }
		}
	}
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
void out(timedelta*& Arr2, int ll);
void outt(datetime*& Arr, int l);
void var1(datetime*& Arr, datetime*& Ar1r2, int l);


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




	////////////////////////////////////////////////////////////////////////////////

	struct tm tim;
	time_t tt = time(NULL);

	localtime_s(&tim, &tt);


	datetime ls1;
	datetime* LArr = new datetime[1];
	ls1.day = tim.tm_mday; ls1.month = tim.tm_mon+1;  ls1.year = tim.tm_year + 1900;  ls1.seconds = tim.tm_sec; ls1.minutes = tim.tm_min; ls1.hours = tim.tm_hour;
	LArr[0] = ls1;
	outt(LArr, 1);
	//////////////////////////////////////////////
	datetime s1;
	datetime* Ar1r2 = new datetime[l];
	for (size_t i = 0; i < l; i++)
	{
		s1.day = Arr[i].day; s1.month = Arr[i].month;  s1.year = Arr[i].year;  s1.seconds = Arr[i].seconds; s1.minutes = Arr[i].minutes; s1.hours = Arr[i].hours;
		Ar1r2[i] = s1;
	}
	datetime s2;
	datetime* Ar2r2 = new datetime[l];
	for (size_t i = 0; i < l; i++)
	{
		s2.day = Arr[i].day; s2.month = Arr[i].month;  s2.year = Arr[i].year;  s2.seconds = Arr[i].seconds; s2.minutes = Arr[i].minutes; s2.hours = Arr[i].hours;
		Ar2r2[i] = s2;
	}
	////////////////////////////////////////////////////////////////////////////
	s1.predd(Ar2r2, l);
	s2.method(Ar1r2, l);
	/////////////////////////////
	int a = -1;
	while (a!=0)
	{
		cout << "Выберете действие:"<<endl<<"1)Вывод timedelta" << endl << "2)Вывод datetime" << endl << "3)Вывод следующий день datetime" << endl << "4)Вывод предыдущей день datetime" << endl << "5)Вывод Var" << endl << "0)Выход"<<endl;
		cin >> a;
		if(a == 1){ out(Arr2, ll); }
		if (a == 2) { outt(Arr, l); }
		if (a == 3) { outt(Ar1r2, l); }
		if (a == 4) { outt(Ar2r2, l); }
		if (a == 5) { var1(Arr, Ar1r2, l); }
	}

}

void out(timedelta*& Arr2, int ll)
{
	cout << "-------"<<endl;
	for (size_t n = 0; n < ll; n++)
	{
		cout << n+1 << ")";
		cout << "day : " << Arr2[n].day << " "
			<< "month : " << Arr2[n].month << " "
			<< "year : " << Arr2[n].year << " "
			<< "seconds : " << Arr2[n].seconds << " "
			<< "minutes : " << Arr2[n].minutes << " "
			<< "hours : " << Arr2[n].hours << endl;
	}
}
void outt(datetime*& Arr, int l)
{
	cout << "--------" << endl;
	for (size_t n = 0; n < l; n++)
	{
		cout << n+1 << ")";
		cout << "day : " << Arr[n].day << " "
			<< "month : " << Arr[n].month << " "
			<< "year : " << Arr[n].year << " "
			<< "seconds : " << Arr[n].seconds << " "
			<< "minutes : " << Arr[n].minutes << " "
			<< "hours : " << Arr[n].hours << endl;
	}
}
void var1(datetime*& Arr, datetime*& Ar1r2, int l)
{
	for (size_t n = 0; n < l; n++)
	{
	 
		if (Arr[n].month != 2) { if (Arr[n].month == 1 || Arr[n].month == 3 || Arr[n].month == 5 || Arr[n].month == 7 || Arr[n].month == 8 || Arr[n].month == 10 || Arr[n].month == 12) { if (Arr[n].day == 31) {
			cout << "day : " << Arr[n].day << " "
				<< "month : " << Arr[n].month << " "
				<< "year : " << Arr[n].year << " "
				<< "seconds : " << Arr[n].seconds << " "
				<< "minutes : " << Arr[n].minutes << " "
				<< "hours : " << Arr[n].hours << endl;
			cout << "следующая дата" << endl;
			cout << "day : " << Ar1r2[n].day << " "
				<< "month : " << Ar1r2[n].month << " "
				<< "year : " << Ar1r2[n].year << " "
				<< "seconds : " << Ar1r2[n].seconds << " "
				<< "minutes : " << Ar1r2[n].minutes << " "
				<< "hours : " << Ar1r2[n].hours << endl << endl;
		} }
		else { if (Arr[n].day == 30) {
			cout << "day : " << Arr[n].day << " "
				<< "month : " << Arr[n].month << " "
				<< "year : " << Arr[n].year << " "
				<< "seconds : " << Arr[n].seconds << " "
				<< "minutes : " << Arr[n].minutes << " "
				<< "hours : " << Arr[n].hours << endl;
			cout << "следующая дата" << endl;
			cout << "day : " << Ar1r2[n].day << " "
				<< "month : " << Ar1r2[n].month << " "
				<< "year : " << Ar1r2[n].year << " "
				<< "seconds : " << Ar1r2[n].seconds << " "
				<< "minutes : " << Ar1r2[n].minutes << " "
				<< "hours : " << Ar1r2[n].hours << endl << endl;
		} }
		}
		else{
			if (Arr[n].year % 4 == 0) {
				if (Arr[n].year % 100 == 0) { if (Arr[n].year % 400 == 0) {
					if (Arr[n].day == 29) {
						cout << "day : " << Arr[n].day << " "
							<< "month : " << Arr[n].month << " "
							<< "year : " << Arr[n].year << " "
							<< "seconds : " << Arr[n].seconds << " "
							<< "minutes : " << Arr[n].minutes << " "
							<< "hours : " << Arr[n].hours << endl;
						cout << "следующая дата" << endl;
						cout << "day : " << Ar1r2[n].day << " "
							<< "month : " << Ar1r2[n].month << " "
							<< "year : " << Ar1r2[n].year << " "
							<< "seconds : " << Ar1r2[n].seconds << " "
							<< "minutes : " << Ar1r2[n].minutes << " "
							<< "hours : " << Ar1r2[n].hours << endl << endl;
					}
				} else {
					if (Arr[n].day == 28) {
						cout << "day : " << Arr[n].day << " "
							<< "month : " << Arr[n].month << " "
							<< "year : " << Arr[n].year << " "
							<< "seconds : " << Arr[n].seconds << " "
							<< "minutes : " << Arr[n].minutes << " "
							<< "hours : " << Arr[n].hours << endl;
						cout << "следующая дата" << endl;
						cout << "day : " << Ar1r2[n].day << " "
							<< "month : " << Ar1r2[n].month << " "
							<< "year : " << Ar1r2[n].year << " "
							<< "seconds : " << Ar1r2[n].seconds << " "
							<< "minutes : " << Ar1r2[n].minutes << " "
							<< "hours : " << Ar1r2[n].hours << endl << endl;
					}
				} }
				else {
					if (Arr[n].day == 29) {
						cout << "day : " << Arr[n].day << " "
							<< "month : " << Arr[n].month << " "
							<< "year : " << Arr[n].year << " "
							<< "seconds : " << Arr[n].seconds << " "
							<< "minutes : " << Arr[n].minutes << " "
							<< "hours : " << Arr[n].hours << endl;
						cout << "следующая дата" << endl;
						cout << "day : " << Ar1r2[n].day << " "
							<< "month : " << Ar1r2[n].month << " "
							<< "year : " << Ar1r2[n].year << " "
							<< "seconds : " << Ar1r2[n].seconds << " "
							<< "minutes : " << Ar1r2[n].minutes << " "
							<< "hours : " << Ar1r2[n].hours << endl << endl;
					}
				}
			}
			else {
				if (Arr[n].day == 28) {
					cout << "day : " << Arr[n].day << " "
						<< "month : " << Arr[n].month << " "
						<< "year : " << Arr[n].year << " "
						<< "seconds : " << Arr[n].seconds << " "
						<< "minutes : " << Arr[n].minutes << " "
						<< "hours : " << Arr[n].hours << endl;
					cout << "следующая дата" << endl;
					cout << "day : " << Ar1r2[n].day << " "
						<< "month : " << Ar1r2[n].month << " "
						<< "year : " << Ar1r2[n].year << " "
						<< "seconds : " << Ar1r2[n].seconds << " "
						<< "minutes : " << Ar1r2[n].minutes << " "
						<< "hours : " << Ar1r2[n].hours << endl;
				}
			}
		}
	}
}

int den(int s,int a, int g)
{

	if (s != 2) {
		if (s == 1 || s == 3 || s == 5 || s == 7 || s == 8 || s == 10 || s == 12) {
			if (a == 31) {
				return 1;
			}
			else { return 0; }
		}
		else {
			if (a == 30) {
				return 1;
			}
			else { return 0; }
		}
	}
	else {
		if (g % 4 == 0) {
			if (g % 100 == 0) {
				if (g % 400 == 0) {
					if (a == 29) {
						return 1;
					}
					else { return 0; }
				}
				else {
					if (a == 28) {
						return 1;
					}
					else { return 0; }
				}
			}
			else {
				if (a == 29) {
					return 1;
				}
				else { return 0; }
			}
		}
		else {
			if (a == 28) {
				return 1;

			}
			else { return 0; }
		}
	}

}

int pden(int s, int a, int g)
{

	if (s != 3) {
		if (s == 5 || s == 7 || s == 10 || s == 12) {
			if (a == 1) {
				return 30;
			}
			else { return 0; }
		}
		else if(s == 2 || s == 4 || s == 6 || s == 8 || s == 9 || s == 11) {
			if (a == 1) {
				return 31;
			}
			else { return 0; }

		}
	}
	else {
		if (a == 1) {
			if (vess(g) == 1) { return 29; }
			else { return 28; }
		}
		else { return 0; }
	}

}

int vess(int s)
{
	if (s % 4 == 0) {
		if (s % 100 == 0) {
			if (s % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
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
