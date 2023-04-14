#include <iostream>
#include <windows.h>
#include "Person.h"
using namespace std;
class Teacher : public Person {
private:
	string subject;
	int grade;

public:
	Teacher(string n = "", int a = 0, string s = "", int g = 0);

	void setSubject(string s);
	void setGrade(int g);
	string getSubject(); 
	int getGrade();
	void checkGrade();

	friend istream& operator >> (istream& is, Teacher& s);
};

Teacher::Teacher(string n, int a, string s, int g) : Person(n, a) {
	subject = s;
	grade = g;
}

void Teacher::setSubject(string s) {
	subject = s;
}

void Teacher::setGrade(int g) {
	grade = g;
}

string Teacher::getSubject() {
	return subject;
}

int Teacher::getGrade() {
	return grade;
}

void Teacher::checkGrade()
{
	if (grade < 4) {
		cout << "������ �������� ��������������������!" << endl;
	}
	else {
		cout << "������ �������� ������������������!" << endl;
	}
}

istream& operator >> (istream& is, Teacher& s) {
	string n, sub;
	int a, g;

	cout << "������� ��� ��������: ";
	is >> n;
	s.setName(n);

	cout << "������� ������� ��������: ";
	is >> a;
	s.setAge(a);

	cout << "������� �������� ��������: ";
	is >> sub;
	s.setSubject(sub);

	cout << "������� ������: ";
	is >> g;
	s.setGrade(g);

	return is;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Teacher student;
	cin >> student;

	cout << "���: " << student.getName() << endl;
	cout << "�������: " << student.getAge() << endl;
	cout << "�������: " << student.getSubject() << endl;
	cout << "������: " << student.getGrade() << endl;

	student.checkGrade();
	
	return 0;
}