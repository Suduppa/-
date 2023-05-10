#include "Person.h"
#include "Event.h"


//конструктор без параметров
Person::Person(void)
{
	name = "";
	age = 0;
}

//деструктор
Person::~Person(void)
{
}

//конструктор с параметрами
Person::Person(string F, int S)
{
	name = F;
	age = S;
}

//конструктор копирования
Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}

//модификаторы (метод изменения полей)
void Person::Set_Name(string F)
{
	name = F;
}

void Person::Set_Age(int S)
{
	age = S;
}


//перегрузка операции присваивания
Person& Person::operator=(const Person& c)
{
	if (&c == this)return *this;
	name = c.name;
	age = c.age;
	return *this;
}

//ввод
void Person::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
}


void Person::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;

	cout << "\n";
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage) //событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "Name = " << GetName() << endl;
			break;
		}
	}
}