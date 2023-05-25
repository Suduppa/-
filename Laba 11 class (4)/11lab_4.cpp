#include <iostream>
#include <stack>
#include <vector>
#include "Time.h"
using namespace std;
typedef stack<Time>St;
typedef vector<Time>Vec;
St make_stack(int n)
{
    St s;
    Time t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        s.push(t);
    }
    return s;
}
void print_stack(St s)
{
    Vec v;
    while (!s.empty())
    {
        cout << s.top() << endl;
        v.push_back(s.top());
        s.pop();
    }
}
Vec copy_stack_to_vector(St s)
{
    Vec v;
    while (!s.empty())
    {
       
        v.push_back(s.top());
        s.pop();
    }
    return v; 
}
St copy_vector_to_stack(Vec v)
{
    St s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);
    }
    return s;
}
Time Max(St s)
{
    Time m = s.top();
    Vec v = copy_stack_to_vector(s);
    while (!s.empty())
    {
        if (s.top() > m)m = s.top();
        s.pop();
    }
    s = copy_vector_to_stack(v);
    return m;
}

void Delete_from_stack(St& s)
{
    Time m;
    Vec v;
    Time t;
    while (!s.empty())
    {
        t = s.top();
        s.pop();
    }
    s = copy_vector_to_stack(v);
}
Time Min(St s)
{
    Time m = s.top();
    Vec v = copy_stack_to_vector(s);
    while (!s.empty())
    {
        if (s.top() < m)m = s.top();
        s.pop();
    }
    s = copy_vector_to_stack(v);
    return m;
}
void Delenie(St& s)
{
    Time m = Min(s);
    Vec v;
    Time t;
    while (!s.empty())
    {
        t = s.top(); 
        v.push_back(t / m);
        s.pop();
    }
    s = copy_vector_to_stack(v);
}
void Add_to_stack(St& s, Time el)
{
    s.push(el);
}
void del_to_queue(St& s, int pos)
{
    int i = 1;
    Vec v;
    Time t;
    while (!s.empty())
    {
        t = s.top();
        
        if (i != pos) v.push_back(t);
        s.pop();
        i++;
    }
    s = copy_vector_to_stack(v);
}
int main()
{
    setlocale(LC_ALL, "Russian"); 

    Time t;
    St s;
    int n;
    cout << "n?";
    cin >> n;
    s = make_stack(n);  
    print_stack(s);     

    cout << "Max: " << Max(s) << endl;

    cout << "del pos?";
    int pos;
    cin >> pos;

    del_to_queue(s, pos);
    print_stack(s);

}