#include "stack.h"

Stck::Stck(int s) {
	for (int i = 0; i < s; i++) {
		pushback(rand() % 10);
	}
	size = s;
}

Stck::Stck() {
	size = 0;
	head = nullptr;
}

Stck::~Stck() {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}

bool Stck::empty() {
	return size == 0;
}

void Stck::pushback(int data) {
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = head;
	head = new_node;
	size++;
}

void Stck::popback() {
	Node* temp = head;
	head = temp->next;
	size--;
	delete temp;
}

int& Stck::operator ()() {
	return size;
}

ostream& operator<<(ostream& out, const Stck& a) {
	Node* curr = a.head;
	while (curr != nullptr) {
		cout << curr->data << "\n";
		curr = curr->next;
	}
	cout << endl;
	return out;
}