#include "stack.h"
#include <iostream>
using namespace std;
setlocale(LC_ALL, "rus");
int main() {
	srand(time(NULL));
	Stck a(10);
	cout << a;
	int num;
	cout << "¬ведите число: "; 
	cin >> num;
	a.popback();
	a.pushback(num);
	cout << a;
	return 0;
}
