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
	void pop_element();
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
		T data;
	};

	Node* head = nullptr;
	int size = 0;
};

template <typename T>
void List<T>::push_front()
{
	T data;
	cout << "Введите данные: ";
	cin >> data;
	Node* temp = head;
	head = new Node(data);
	head->pnext = temp;
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
		--size;
		return 1;
	}
	else{ system("cls"); cout << "Список пуст!\n\n"; return 0; }
}

template<typename T>
void List<T>::push_back()
{
	T data;
	cout << "Введите данные: ";
	cin >> data;
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node* current = head;
		while (current->pnext != nullptr)
			current = current->pnext;
		current->pnext = new Node(data);
	}
	++size;
}

template<typename T>
int List<T>::pop_back()
{
	if (head != nullptr)
	{
		Node* current = head;
		for (int i = 0; i < size - 1; i++)
			current = current->pnext;
		delete current->pnext;
		current->pnext = nullptr;
		--size;
		return 1;
	}
	else { system("cls"); cout << "Список пуст!\n\n"; return 0; }
}

template<typename T>
void List<T>::show_list()
{
	if (head != nullptr)
	{
		cout << "Список: ";
		Node* current = head;
		for (size_t i = 0; i < size; i++)
		{
			cout << current->data << " ";
			current = current->pnext;
		}
		cout << endl << endl;
	}
	else
		cout << "Список пуст!\n\n";

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
				cout << "Введите данные: ";
				cin >> data;
				Node* current = head;
				for (int i = 0; i < number - 1; i++)
					current = current->pnext;
				Node* temp = current->pnext;
				current->pnext = new Node(data);
				current = current->pnext;
				current->pnext = temp;
				++size;
			}
			return 1;
		}
		else { system("cls"); cout << "Ошибка ввода!\n\n"; return 0; }
	}
	else { system("cls"); cout << "Список пуст!\n\n"; return 0; }
}

template<typename T>
void List<T>::add_several_elements()
{
	int n, choice;
	T data;
	cout << "Введите 1 - добавить элементы в начало списка\nВведите 2 - добавить элементы после выбранного элемента\nВведите 3 - добавить элементы в конец списка\n\n";
	cout << "Ваш выбор ответа: ";
	cin >> choice;

	system("cls");
	switch (choice)
	{
	case 1:
		cout << "Количество добавляемых элементов: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_front();
		system("cls"); cout << "Данные были успешно добавлены!\n\n";
		break;
	case 2:
		if (head != nullptr)
		{
			show_list();
			cout << "Количество добавляемых элементов: ";
			cin >> n;
			int number;
			cout << "После какого номера элемента добавить новые: ";
			cin >> number;
			cout << endl;
			for (int i = 0; i < n; i++)
				add_after(number++);
			system("cls"); cout << "Данные были успешно добавлены!\n\n";
		}
		else { system("cls"); cout << "Список пуст!\n\n"; }
		break;
	case 3:
		cout << "Количество добавляемых элементов: ";
		cin >> n;
		cout << endl;
		for (int i = 0; i < n; i++)
			push_back();
		system("cls"); cout << "Данные были успешно добавлены!\n\n";
		break;
	default:
		cout << "Ошибка ввода. Повторите попытку.\n\n";
		break;
	}
}

template<typename T>
void List<T>::pop_element()
{
	if (head != nullptr)
	{
		show_list();
		int number;
		cout << "Элемент под каким номером удалить: ";
		cin >> number;
		if (number >= 1 && number <= size)
		{
			if (number == size)
				pop_back();
			else if (number == 1)
				pop_front();
			else
			{
				Node* current = head;
				for (int i = 0; i < number - 2; i++)
					current = current->pnext;
				Node* temp = current->pnext;
				current->pnext = temp->pnext;
				delete temp;
				--size;
			}
			system("cls"); cout << "Данные были успешно удалены!\n\n";
		}
		else{ system("cls"); cout << "Ошибка ввода!\n\n"; }
	}
	else{ system("cls"); cout << "Список пуст!\n\n"; }

}

template<typename T>
void List<T>::delete_several_elements()
{
	show_list();

	if (head != nullptr)
	{
		int start, count;
		cout << "С какого элемента начать удаление: ";
		cin >> start;

		if (start >= 1 && start <= size)
		{
			cout << "Количество удаляемых элементов: ";
			cin >> count;
			if (start + count <= size + 1)
			{
				if (start == 1)
					for (int i = 0; i < count; i++)
						pop_front();
				else
				{
					Node* current = head;
					for (int i = 0; i < start - 2; i++)
						current = current->pnext;
					for (int i = 0; i < count; i++)
					{
						Node* temp = current->pnext;
						current->pnext = temp->pnext;
						delete temp;
					}
					size -= count;
				}
				system("cls"); cout << "Данные были успешно удалены!\n\n";
			}
			else { system("cls"); cout << "Ошибка ввода!\n\n"; }
		}
		else { system("cls"); cout << "Ошибка ввода!\n\n"; }
	}
}

int main()
{
	system("chcp 1251 >> null");

	List<int> list1;
	int data;

	int f = 1;
	while (f)
	{
		int choice;
		cout << "Введите 1 - добавить элемент в начало списка\nВведите 2 - добавить элемент в конец списка\nВведите 3 - добавить элемент после заданного\nВведите 4 - добавить несколько элементов\nВведите 5 - удалить элемент из начала списка\nВведите 6 - удалить элемент из конца списка\nВведите 7 - удалить элемент после заданного\nВведите 8 - удалить несколько элементов\nВведите 9 - просмотреть список\nВведите 10 - завершить работу программы\n\n";
		cout << "Ваш выбор ответа: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			list1.push_front();
			system("cls");
			cout << "Данные были успешно добавлены!\n\n";
			break;
		case 2:
			system("cls");
			list1.push_back();
			system("cls");
			cout << "Данные были успешно добавлены!\n\n";
			break;
		case 3:
			if (list1.head != nullptr)
			{
				system("cls");
				list1.show_list();
				int number;
				cout << "После какого номера элемента добавить новый: ";
				cin >> number;
				if (list1.add_after(number) == 1)
				{
					system("cls");
					cout << "Данные были успешно удалены!\n\n";
				}
			}
			else { system("cls"); cout << "Список пуст!\n\n"; }
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
				cout << "Данные были успешно удалены!\n\n";
			}
			break;
		case 6:
			system("cls");
			if (list1.pop_back() == 1)
			{
				system("cls");
				cout << "Данные были успешно удалены!\n\n";
			}
			break;
		case 7:
			system("cls");
			list1.pop_element();
			break;
		case 8:
			system("cls");
			list1.delete_several_elements();
			break;
		case 9:
			system("cls");
			list1.show_list();
			break;
		case 10:
			system("cls"); cout << "Завершение работы программы.\n";
			f = 0;
			break;
		default:
			system("cls"); cout << "Ошибка ввода. Повторите попытку.\n\n";
			break;
		}
	}
	return 0;
}