
#include <iostream>
#include "Vector.h"
#include "Time.h"
#include <windows.h>    
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");

	Vector<int>A(5, 0);
	cout << "Введите значения вектора: ";
	cin >> A;
	cout << A << endl;

	Vector <int>B(10, 1);
	cout << B << endl;

	B = A;
	cout << B << endl;

	cout << A[2] << endl;

	cout << A[2] + A[2] << endl;

	cout << "size=" << A() << endl;

	B = A + 10;
	cout << B << endl;
	Time t;
	cin >> t;
	cout << t;
	Time k;
	cout << " Введите новый объект: \n";
	cin >> k;
	Time p;
	p = t + k;
	cout << "Сложение двух времен: " << p;
}

