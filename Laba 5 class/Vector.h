#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;
class Vector
{
public:
	Vector();
	Vector(int);
public:
	~Vector();
	void Add(Object*);
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	Object** beg;
	int size;
	int cur;
};

