#include "Emloyee.h"


//����������� ��� ����������
Emloyee::Emloyee(void) :Person()
{
	wage = 0;
	post = "";
}

//���������
Emloyee::~Emloyee(void)
{
}

//����������� � �����������
Emloyee::Emloyee(string F, int S, int G, string R) :Person(F, S)
{
	wage = G;
	post = R;
}

//����������� �����������
Emloyee::Emloyee(const Emloyee& L)
{
	name = L.name;
	age = L.age;
	wage = L.wage;
	post = L.post;
}

//�����������
void Emloyee::Set_Point(int G)
{
	wage = G;
}

//�����������
void Emloyee::Set_Spec(string R)
{
	post = R;
}

//������� ������������
Emloyee& Emloyee::operator=(const Emloyee& L)
{
	if (&L == this)return *this;
	name = L.name;
	age = L.age;
	wage = L.wage;
	post = L.post;
	return *this;
}

//����
void Emloyee::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
	cout << "\nZarplata:"; cin >> wage;
	cout << "\nDolgnost : "; cin >> post;
}

// �����
void Emloyee::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << "\nZarplata: " << wage;
	cout << "\nDolgnost: " << post;
	cout << "\n";
}

