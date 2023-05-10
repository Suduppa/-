#include "Vector.h"
#include "Event.h"
#include "Person.h"
#include "Emloyee.h"

Vector::~Vector(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

Vector::Vector()
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}

void Vector::Add()
{
	Object* p;
	
	cout << "1.Person" << endl;
	cout << "2.Emloyee" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new (Person);
		a->Input();
		p = a;
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2) 
		{
			Emloyee* b = new Emloyee;
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;
}

void Vector::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

void Vector::Name()
{
	if (cur == 0) 
	{
		cout << "Объекты с именами отсутствуют!" << endl;
		return;
	}
	string name = "";
	int a;
	cout << "\nУкажите номер объекта: " << endl;
	cin >> a;
	Object** p = beg;
	p = p + a - 1;
	name = (*p)->GetName();

	cout << "Имя выбранного сотрудника: " << name << endl;
}

int Vector::operator ()()
{
	return cur;
}

void Vector::Del()
{
	if (cur == 0)return;
	cur--;
}
void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}