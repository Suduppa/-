#include "Time.h"
#include <iostream>
#include <windows.h>   
using namespace std;
Time& Time::operator=(const Time& t)
{

	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time& Time::operator++()
{
	int temp = min * 60 + sec;
	temp++;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}

Time Time::operator ++(int)
{
	int temp = min * 60 + sec;
	temp++;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

Time Time::operator-(const Time& t)
{
	int temp1 = min * 60 - sec;
	int temp2 = t.min * 60 - t.sec;
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "¬ведите минуты: "; in >> t.min;
	cout << "¬ведите секунды: "; in >> t.sec;
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}

fstream& operator>>(fstream& fin, Time& p)
{
	fin >> p.min;
	fin >> p.sec;
	return fin;
}
fstream& operator <<(fstream& fout, const Time& p)
{
	fout << to_string(p.min) << "\n" << p.sec << "\n";
	return fout;
}