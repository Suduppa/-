#include <iostream>
#include <vector>
#include "Time.h"
using namespace std;
typedef vector<Time> Vec;
Vec make_vector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		Time t;
		cin >> t;
		v.push_back(t);
	}
	return v;
}
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
Time srednee(Vec v)
{
	int m = 0;
	int s = 0;
	for (int i = 0; i < v.size(); i++)
	{
		m += v[i].get_min();
		s += v[i].get_sec();
	}
	int n = v.size();
	Time p;
	p.set_min(m / n);
	p.set_sec(s / n);
	return p;
}
void add_vector(Vec& v, Time el, int pos)
{
	v.insert(v.begin() + pos, el);
}
void del_vector(Vec& v, int pos)
{
	v.erase(v.begin() + pos);
}
int min(Vec v)
{
	Time m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m > v[i])
		{
			m = v[i];
			n = i;
		}
	return n;
}
int max(Vec v)
{
	Time m = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i]; 
			n = i;
		}
	return n;
}
void delenie(Vec& v)
{
	int m = min(v);
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] / v[m];
}
void main()
{
	setlocale(LC_ALL, "Russian");

	try
	{
		vector<Time> v;
		vector<Time>::iterator vi = v.begin();
		int n;
		cout << "Kolvo elementov: "; cin >> n;
		v = make_vector(n);
		print_vector(v);
		Time el = srednee(v);
		cout << "Position for sredgnego znacheniya: ";
		int pos;
		cin >> pos;
		if (pos > v.size())throw 1;
		add_vector(v, el, pos);
		print_vector(v);
		cout << "Max Element: " << v[max(v)] << "\n";
		del_vector(v, max(v)); 
		cout << "\nДеление: ";
		delenie(v);
		print_vector(v);
	}
	catch (int)
	{
		cout << "error!";
	}
}