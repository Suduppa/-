#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct List
{
	void push_front();
	int pop_front();
	void push_back();
	int pop_back();
	int add_after(int number);
	int pop_element(int number);

	void add_several_elements();
	void delete_several_elements();

	void show_list();

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
	int size = 0;
};

template <typename T>
void List<T>::push_front()
{
	T data;
	cout << "������� ������: ";
	cin >> data;
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* temp = head;
		head = new Node(data);
		temp->pprev = head;
		head->pnext = temp;
	}
	++size;
}

template<typename T>
int List<T>::pop_front()
{
	if (head != nullptr)
	{
		Node* temp = head->pnext;
		delete head;
		head = temp;
		if (head != nullptr)
			head->pprev = 0;
		else
			tail = nullptr;
		--size;
		return 1;
	}
	else
	{
		system("cls"); cout << "������ ����!\n\n";
		return 0;
	}
}

template<typename T>
void List<T>::push_back()
{
	T data;
	cout << "������� ������: ";
	cin >> data;
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* current = tail;
		current->pnext = new Node(data);
		tail = current->pnext;
		tail->pprev = current;
		tail->pnext = 0;
	}
	++size;
}

template<typename T>
int List<T>::pop_back()
{
	if (head != nullptr)
	{
		Node* current = tail->pprev;
		delete tail;
		tail = current;
		if (tail != nullptr)
			current->pnext = nullptr;
		else
			head = nullptr;
		--size;
		return 1;
	}
	else { system("cls"); cout << "������ ����!\n\n"; return 0; }
}

template<typename T>
void List<T>::show_list()
{
	if (head != nullptr)
	{
		int choice;
		cout << "������� 1 - ����� ������ � ������\n������� 2 - ����� ������ � �����\n\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			cout << "������: ";
			Node* current = head;
			for (size_t i = 0; i < size; i++)
			{
				cout << current->data << " ";
				current = current->pnext;
			}
			cout << endl << endl;
			break;
		}
		case 2:
		{
			cout << "������: ";
			Node* current = tail;
			for (size_t i = size; i > 0; i--)
			{
				cout << current->data << " ";
				current = current->pprev;
			}
			cout << endl << endl;
			break;
		}
		default:
			system("cls"); cout << "������ �����!\n\n";
			break;
		}
	}
	else { system("cls"); cout << "������ ����!\n\n"; }
}

template<typename T>
int List<T>::add_after(int number)
{
	if (head != nullptr)
	{
		if (number >= 0 && number <= size)
		{
			if (number == size)
				push_back();
			else if (number == 0)
				push_front();
			else
			{
				T data;
				cout << "������� ������: ";
				cin >> data;
				if (number <= size / 2)
				{
					Node* current = head;
					for (int i = 0; i < number - 1; i++)
						current = current->pnext;
					Node* temp = current->pnext;
					current->pnext = new Node(data);
					current->pprev = current;
					current = current->pnext;
					current->pnext = temp;
					++size;
				}
				else
				{
					Node* current = tail;
					for (int i = size; i > number; i--)
						current = current->pprev;
					Node* temp = current->pnext;
					Node* temp2 = current;
					current->pnext = new Node(data);
					temp->pprev = current->pnext;
					current = current->pnext;
					current->pprev = temp2;
					current->pnext = temp;
					++size;
				}
			}
			return 1;
		}
		else { system("cls"); cout << "������ �����!\n\n"; return 0; }
	}
	else { system("cls"); cout << "������ ����!\n\n"; return 0; }
}

template<typename T>
void List<T>::add_several_elements()
{
	int n, choice;
	T data;
	cout << "������� 1 - �������� �������� � ������ ������\n������� 2 - �������� �������� ����� ���������� ��������\n������� 3 - �������� �������� � ����� ������\n\n";
	cout << "��� ����� ������: ";
	cin >> choice;

	system("cls");
	switch (choice)
	{
	case 1:
		cout << "���������� ����������� ���������: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_front();
		system("cls"); cout << "������ ���� ������� ���������!\n\n";
		break;
	case 2:
		if (head != nullptr)
		{
			show_list();
			cout << "���������� ����������� ���������: ";
			cin >> n;
			int number;
			cout << "����� ������ �������� �������� ������: ";
			cin >> number;
			cout << endl;
			for (int i = 0; i < n; i++)
				add_after(number++);
			system("cls"); cout << "������ ���� ������� ���������!\n\n";
		}
		else { system("cls"); cout << "������ ����!\n\n"; }
		break;
	case 3:
		cout << "���������� ����������� ���������: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_back();
		system("cls"); cout << "������ ���� ������� ���������!\n\n";
		break;
	default:
		cout << "������ �����. ��������� �������.\n\n";
		break;
	}
}

template<typename T>
int List<T>::pop_element(int number)
{
	if (head != nullptr)
	{
		if (number >= 1 && number <= size)
		{
			if (number == size)
				pop_back();
			else if (number == 1)
				pop_front();
			else
			{
				if (number <= size / 2)
				{
					Node* current = head;
					for (int i = 0; i < number - 1; i++)
						current = current->pnext;
					Node* temp = current->pprev;
					Node* temp2 = current->pnext;
					delete current;
					temp->pnext = temp2;
					temp2->pprev = temp;
				}
				else
				{
					Node* current = tail;
					for (int i = size; i > number; i--)
						current = current->pprev;
					Node* temp = current->pprev;
					Node* temp2 = current->pnext;
					delete current;
					temp->pnext = temp2;
					temp2->pprev = temp;
				}
				--size;
			}
			return 1;
		}
		else { system("cls"); cout << "������ �����!\n\n"; return 0; }
	}
	else { system("cls"); cout << "������ ����!\n\n"; return 0; }

}

template<typename T>
void List<T>::delete_several_elements()
{
	if (head != nullptr)
	{
		int start, count, choice;
		cout << "������� 1 - ������� �����\n������� 2 - ������� ������\n\n��� ����� ������: ";
		cin >> choice;
		cout << "\n� ������ �������� ������ ��������: ";
		cin >> start;
		if (start >= 1 && start <= size)
		{
			cout << "���������� ��������� ���������: ";
			cin >> count;
			if (start == 1 && choice == 2 && ((start + count) <= (size + 1)))
				for (int i = 0; i < count; i++)
					pop_front();
			else if (start == size && choice == 1 && (start - count >= 0))
				for (int i = 0; i < count; i++)
					pop_back();
			else if (choice == 2 && ((start + count) <= (size + 1)))
				for (int i = 0; i < count; i++)
					pop_element(start);
			else if (choice == 1 && (start - count >= 0))
				for (int i = 0; i < count; i++)
					pop_element(start--);
			else { system("cls"); cout << "������ �����!\n\n"; return; }
			system("cls"); cout << "������ ���� ������� �������!\n\n";
		}
		else { system("cls"); cout << "������ �����!\n\n"; }
	}
}

int main()
{
	system("chcp 1251 >> null");

	List<string> list1;
	List<int> list2;
	int data;

	int f = 1;
	while (f)
	{
		int choice;
		cout << "������� 1 - �������� ������� � ������ ������\n������� 2 - �������� ������� � ����� ������\n������� 3 - �������� ������� ����� ���������\n������� 4 - �������� ��������� ���������\n������� 5 - ������� ������� �� ������ ������\n������� 6 - ������� ������� �� ����� ������\n������� 7 - ������� �������� �������\n������� 8 - ������� ��������� ���������\n������� 9 - ����������� ������\n������� 10 - ��������� ������ ���������\n\n";
		cout << "��� ����� ������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			list1.push_front();
			system("cls");
			cout << "������ ���� ������� ���������!\n\n";
			break;
		case 2:
			system("cls");
			list1.push_back();
			system("cls");
			cout << "������ ���� ������� ���������!\n\n";
			break;
		case 3:
			if (list1.head != nullptr)
			{
				system("cls");
				list1.show_list();
				int number;
				cout << "����� ������ ������ �������� �������� �����: ";
				cin >> number;
				if (list1.add_after(number) == 1)
				{
					system("cls");
					cout << "������ ���� ������� �������!\n\n";
				}
			}
			else { system("cls"); cout << "������ ����!\n\n"; }
			break;
		case 4:
			system("cls");
			list1.add_several_elements();
			break;
		case 5:
			system("cls");
			if (list1.pop_front() == 1)
			{
				system("cls");
				cout << "������ ���� ������� �������!\n\n";
			}
			break;
		case 6:
			system("cls");
			if (list1.pop_back() == 1)
			{
				system("cls");
				cout << "������ ���� ������� �������!\n\n";
			}
			break;
		case 7:
			system("cls");
			list1.show_list();
			if (list1.head != nullptr)
			{
				int number;
				cout << "������� ��� ����� ������� �������: ";
				cin >> number;
				list1.pop_element(number);
				system("cls"); cout << "������ ���� ������� �������!\n\n";
			}
			break;
		case 8:
			system("cls");
			list1.show_list();
			list1.delete_several_elements();
			break;
		case 9:
			system("cls");
			list1.show_list();
			break;
		case 10:
			system("cls"); cout << "���������� ������ ���������.\n";
			f = 0;
			break;
		default:
			system("cls"); cout << "������ �����. ��������� �������.\n\n";
			break;
		}
	}
	return 0;
}