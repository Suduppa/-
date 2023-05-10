#pragma once
#include <string>
#include "Person.h"

class Emloyee :
	public Person
{
public:
	Emloyee(void);
public:
	~Emloyee(void);
	Emloyee(string, int, int, string);
	Emloyee(const Emloyee&);
	void Set_Point(int);   
	void Set_Spec(string); 
	void Input();
	void Show();
	Emloyee& operator=(const Emloyee&);	
protected:
	int wage;	   
	string post;  
};
