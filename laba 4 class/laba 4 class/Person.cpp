#include "Person.h"
using namespace std;
Person::Person(string n, int a) {
	name = n;
	age = a;
}

void Person::setName(string n) {
	name = n;
}

void Person::setAge(int a) {
	age = a;
}

string Person::getName() {
	return name;
}

int Person::getAge() {
	return age;
}