#include <iostream>
#include <set>
using namespace std;
typedef set<float>TSet;
set<float> ::iterator it;
TSet make_set(int n)
{
	TSet m;
	float a;
	for (int i = 0; i < n; i++)
	{
		cout << "Znachenie: ";
		cin >> a;
		m.insert(a);
	}
	return m;
}
void print_set(TSet m)
{
	for (it = m.begin(); it != m.end(); it++)
		cout << *it << "  ";
}
TSet erase_set(TSet m, float el)
{
	for (it = m.begin(); it != m.end();)
	{
		float n = *it;
		if (el == n)
		{
			cout << *it << endl;
			m.erase(it++);
		}
		else ++it;
	}
	return m;
}
float Min_set(TSet m)
{
	float min, temp;
	it = m.begin();
	min = *it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		temp = *it;
		if (min > temp)
		{
			min = temp;
		}
	}
	return min;
}
float Max_set(TSet m)
{
	double max, temp;
	it = m.begin();
	max = *it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		temp = *it;
		if (max < temp)
		{
			max = temp;
		}
	}
	return max;
}
TSet zadanie(TSet m, float min, float max)
{
	for (it = m.begin(); it != m.end(); ++it)
	{
		float h = *it + min - max;
		cout << h << "  ";
	}
	return m;
}
void main()
{
	int n;
	cout << "Kolvo-elementov: "; cin >> n;
	TSet m = make_set(n);
	print_set(m);
	float d;
	cout << "Kakoi udalit (znachenie)'?";
	cin >> d;
	TSet j = erase_set(m, d);
	print_set(j);
	float h = Min_set(j);
	float u;
	cout << "Dobavit element: " << endl;
	cin >> u;
	j.insert(u);
	print_set(j);
	cout << endl;
	float g = Max_set(j);
	cout << "dobavim max-min" << endl;
	zadanie(j, h, g);
}