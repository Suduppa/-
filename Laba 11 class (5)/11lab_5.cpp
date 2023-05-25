#include "Time.h" 
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;
int main()
{
	Vector<Time>v(3);
	v.Print();
	cout << "Min=" << v.Min() << endl;
	v.Add();
	v.Print();
	cout << "pos for del?";
	int pos;
	cin >> pos;
	v.Del(pos);
	v.Print();
	cout << "plusuem max+min+element" << endl;
	v.Summa();
	v.Print();
}