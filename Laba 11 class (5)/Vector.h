#include <iostream>
#include <stack>
#include <vector>
using namespace std;
template<class T>
class Vector
{
	stack <T> s;
	int len;
public:
	Vector();
	Vector(int n);
	void Print();
	void Add();
	void Razn();
	T Max();
	T Min();
	void Del(int pos);
	void Summa();
};
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
}
template <class T>
void Vector<T>::Print()
{
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
template <class T>
void Vector<T>::Add()
{
	T m = Min();
	s.push(m);
}
template <class T>
void Vector<T>::Razn()
{
	T min = Min();
	T max = Max();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t -max - min);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
template <class T>
T Vector<T>::Max()
{
	T m = s.top();
	
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() > m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		if (s.top() < m)m = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return m;
}
template <class T>
void Vector<T>::Del(int pos)
{
	vector<T> v;
	T t;
	int i = 1;
	while (!s.empty())
	{
		t = s.top();
		if (i != pos)v.push_back(t);
		s.pop();
		i++;
	}
	s = copy_vector_to_stack(v);
}
template <class T>
void Vector<T>::Summa()
{
	T m = Min();
	T ma = Max();
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t + m + ma);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}
