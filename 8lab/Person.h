#pragma once
#include <string>
#include <iostream>
#include "object.h"
#include "Event.h"
using namespace std;
class Person :
	public Object
{
	
public:
	Person(void);
public:
	
	virtual ~Person(void);
	
	Person(string, int);
	
	Person(const Person&);
	
	string GetName() { return name; }
	int GetAge() { return age; }

	void Set_Name(string);
	void Set_Age(int);
	void Input();
	void Show();

	Person& operator=(const Person&);
	void HandleEvent(const TEvent& e);

protected:
	string name;
	int age;	 
};
