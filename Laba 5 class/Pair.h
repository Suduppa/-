#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Pair :public Object
{
public:
	Pair() {first = 0; second = 0;}
	~Pair() {};
	void Show() override;
	Pair operator+(const Pair&);
	Pair operator-(const Pair&);
	Pair operator/(const Pair&);
	Pair(int F, int S) {first = F; second = S;}
	Pair(const Pair& Pair) {first = Pair.first; second = Pair.second;}
	int Get_first() { return first; }
	int Get_second() { return second; }
	void Set_first(int F) { first = F; }
	void Set_second(int S) { second = S; }
	Pair& operator=(const Pair&);
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
protected:
	int first;
	int second;
};
