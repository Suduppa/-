#include "book.h"
book make_book()
{
	setlocale(LC_ALL, "rus");
	string name, author;
	int age;
	cout << "������� �������� �����, ������ � ��� �������" << endl;
	cin >> name >> author >> age;
	book t(name, author, age);
	return t;
}
void print_book(book t)
{
	t.show();
}

void main()
{
	setlocale(LC_ALL, "rus");
	book a;
	a.show();
	book b("����������� �����", "������", 1836);
	b.show();
	book c = b;
	c.set_name("�����");
	c.set_author("����");
	c.set_age(2281337);
	print_book(c);
	a = make_book();
	a.show();
}
