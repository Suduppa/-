
#include "Object.h"
#include "Pair.h"
#include "Money.h"
#include "Vector.h"
#include <iostream>
using namespace std;
void main()
{
	Vector(3);

	Vector v(5);
	Pair a;
	cin >> a;
	Money b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p); 
	cout << v;

	Pair t1;
	cin >> t1;
	cout << t1 << endl << "--------------";

	Pair t2(4, 6);
	cout << endl;
	cout << t1 + t2 << endl;
	cout << t1 - t2 << endl;
	cout << t1 / t2 << endl << "--------------" << endl;

	Money t3;
	cin >> t3;
	cout << t3;
	cout << endl << "--------------" << endl;
	Money t4(2, 10);
	cout << t3 + t4 << endl;
	cout << t3 - t4 << endl;
	cout << t3 / t4 << endl << "--------------" << endl;
}