#pragma once
#include <string>
using namespace std;
class Person {
protected:
	string name;
	int age;

public:
	Person(string n, int a);

	void setName(string n);
	void setAge(int a);
	string getName();
	int getAge();
};