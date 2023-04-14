#include "book.h"
book make_book()
{
	setlocale(LC_ALL, "rus");
	string name, author;
	int age;
	cout << "Введите название книги, автора и год издания" << endl;
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
	book b("Капитанская дочка", "Пушкин", 1836);
	b.show();
	book c = b;
	c.set_name("Волки");
	c.set_author("ауфф");
	c.set_age(2281337);
	print_book(c);
	a = make_book();
	a.show();
}
