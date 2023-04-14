#include <iostream>
using namespace std;

template<typename T>
struct stack
{
	void push(T data);
	void pop();
	int getSize();
	void showLastElement();

	struct Node
	{
		Node(T data)
		{
			this->data = data;
		}
		Node* pnext = nullptr;
		T data;
	};
	Node* head = nullptr;
	int size = 0;
};

template<typename T>
void stack<T>::push(T data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* temp = head;
		head = new Node(data);
		head->pnext = temp;
	}
	++size;
}

template<typename T>
void stack<T>::pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = temp->pnext;
		delete temp;
		--size;
	}
	else
		cout << "Стек пуст!" << endl;
}

template<typename T>
int stack<T>::getSize()
{
	return size;
}

template<typename T>
void stack<T>::showLastElement()
{
	if (head != nullptr)
		cout << head->data << endl;
	else
		cout << "Стек пуст!" << endl;
}

int main()
{
	system("chcp 1251 >> null");
	stack<int> s1;
	s1.push(5);
	s1.push(10);
	s1.push(100);
	s1.pop();
	cout << s1.getSize() << endl;
	s1.showLastElement();
	return 0;
}