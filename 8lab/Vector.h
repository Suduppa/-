#pragma once
#include "object.h"
#include <string>
#include <iostream>
using namespace std;
class Vector
{
public:
	Vector(int);
	Vector();
public:
	~Vector(void);
	void Add();
	void Del();
	void Show();
	void Name();
	int operator()();
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};