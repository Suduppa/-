#pragma once
#include <iostream>
using namespace std;

struct Node {
	Node* next = nullptr;
	int data = 0;
};

class Stck {
private:
	int size;
	Node* head = nullptr;
public:
	Stck();
	Stck(int s);
	~Stck();
	void pushback(int data);
	void popback();
	bool empty();
	int& operator()();
	friend ostream& operator <<(ostream&, const Stck&);
};