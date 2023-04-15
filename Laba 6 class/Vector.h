#include <iostream>
using namespace std;

class Iterator
{
	friend class Vector;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }

	
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	
	void operator++() { ++elem; };

	void operator--() { --elem; }
	
	int& operator *() const { return*elem; }
private:
	int* elem;
};

class Vector
{
public:
	
	Vector(int s, int k = 0);
	
	Vector(const Vector& a);
	
	~Vector();
	
	Vector& operator=(const Vector& a);
	
	int& operator[](int index);
	
	Vector operator*(Vector&);
	
	int operator()();
	
	friend ostream& operator<<(ostream& out, const Vector& a);
	friend istream& operator>>(istream& in, Vector& a);
	Iterator first() { return beg; }
	Iterator last() { return end; }
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

