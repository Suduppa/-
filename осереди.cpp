#include <iostream>
using namespace std;

template<typename T>
struct queue
{
	void push(T data);
	void pop();
	int getSize();
	void showBackElement();
	void showFrontElement();

	struct Node
	{
		Node(T data)
		{
			this->data = data;
		}
		Node* pnext = nullptr;
		Node* pprev = nullptr;
		T data;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int size = 0;
};

template<typename T>
void queue<T>::push(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* temp = tail;
		tail = new Node(data);
		temp->pnext = tail;
		tail->pprev = temp;
	}
	++size;
}

template<typename T>
void queue<T>::pop()
{
	if (head != nullptr)
	{
		Node* temp = head;
		head = temp->pnext;
		delete temp;
		if (head != nullptr)
			head->pprev = 0;
		else
			tail = head;
	}
	--size;
}

template<typename T>
int queue<T>::getSize()
{
	return size;
}

template<typename T>
void queue<T>::showBackElement()
{
	if (tail != nullptr)
		cout << tail->data;
	else { cout << "Очередь пуста!" << endl; return; }
}

template<typename T>
void queue<T>::showFrontElement()
{
	if (head != nullptr)
		cout << head->data;
	else { cout << "Очередь пуста!" << endl; return; }
}

int main()
{
	system("chcp 1251 >> null");
	queue<int> queue1;
	queue1.push(5);
	queue1.push(15);
	queue1.push(10);
	queue1.showFrontElement();
	cout << endl;
	queue1.showBackElement();
	return 0;
}