
#include "Vector.h"
#include "Error.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		int size;
		cout << "Введите количество элементов в векторе: " << endl;
		cin >> size;
		Vector x(size);
		Vector y;
		cout << "Размерность вектора: " << x() << endl; 
		cout << "Для доступа к индексу, введите его номер: ";
		int i;
		cin >> i;
		cout << x[i] << endl; 
		--x;
		cout << x;
		++x;
		cout << x;
	}
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}