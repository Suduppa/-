#include "Emloyee.h"


//конструктор без параметров
Emloyee::Emloyee(void) :Person()
{
	wage = 0;
	post = "";
}

//дестрктор
Emloyee::~Emloyee(void)
{
}

//конструктор с параметрами
Emloyee::Emloyee(string F, int S, int G, string R) :Person(F, S)
{
	wage = G;
	post = R;
}

//конструктор копирования
Emloyee::Emloyee(const Emloyee& L)
{
	name = L.name;
	age = L.age;
	wage = L.wage;
	post = L.post;
}

//модификатор
void Emloyee::Set_Point(int G)
{
	wage = G;
}

//модификатор
void Emloyee::Set_Spec(string R)
{
	post = R;
}

//оперция присваивания
Emloyee& Emloyee::operator=(const Emloyee& L)
{
	if (&L == this)return *this;
	name = L.name;
	age = L.age;
	wage = L.wage;
	post = L.post;
	return *this;
}

//ввод
void Emloyee::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
	cout << "\nZarplata:"; cin >> wage;
	cout << "\nDolgnost : "; cin >> post;
}

// Вывод
void Emloyee::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << "\nZarplata: " << wage;
	cout << "\nDolgnost: " << post;
	cout << "\n";
}

