#include <iostream>  
#include "Time.h"
#include <algorithm> 
#include <set>
using  namespace  std;
typedef  multiset<int> mst;  
typedef multiset<int> ::iterator it;
 
mst make_map(int n)
{
    mst m;
    int a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;
        m.insert(a);
    }
    return m;
}
void print_map(mst v)
{
    multiset <int> ::iterator it = v.begin();

    cout << "Отсортированный вариант: " << endl;
    for (int i = 1; it != v.end(); i++, it++) 
    {
        cout << *it << " ";
    }
}
int srednee(mst v)
{
    int s = 0;
    multiset <int> ::iterator it = v.begin();
    for (int i = 1; it != v.end(); i++, it++)
    {
        s += *it;
    }
    int n = v.size();
    return s / n;
}
Time s;
int main()
{
    setlocale(LC_ALL, "Russian");
	int n;
    Time t;
    cout << "kolvo elementov: ";
    cin >> n;                
    mst v = make_map(n);   
    print_map(v);      
    mst::iterator i;
    i = max_element(v.begin(), v.end());
    s = srednee(v);
    cout << "sred=" << s << endl;
    return 0;
}