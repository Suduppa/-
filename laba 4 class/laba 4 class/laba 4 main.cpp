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
		cout << "Оценка студента неудовлетворительная!" << endl;
	}
	else {
		cout << "Оценка студента удовлетворительная!" << endl;
	}
}

istream& operator >> (istream& is, Teacher& s) {
	string n, sub;
	int a, g;

	cout << "Введите имя студента: ";
	is >> n;
	s.setName(n);

	cout << "Введите возраст студента: ";
	is >> a;
	s.setAge(a);

	cout << "Введите название предмета: ";
	is >> sub;
	s.setSubject(sub);

	cout << "Введите оценку: ";
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

	cout << "Имя: " << student.getName() << endl;
	cout << "Возраст: " << student.getAge() << endl;
	cout << "Предмет: " << student.getSubject() << endl;
	cout << "Оценка: " << student.getGrade() << endl;

	student.checkGrade();
	
	return 0;
}