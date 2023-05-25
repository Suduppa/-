#include "Vector.h"
#include <iostream>
#include "Time.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
	Vector<Time>vec(2);    
    vec.Print();       
    Time s = vec.Srednee(); 
    cout << "Srednee=" << s << endl;
    cout << "pos?";
    int p;
    cin >> p
    p = vec.Min();  
    vec.Add(s, p);
    vec.Print();
    p = vec.Max();  
    vec.Del(p);   
    vec.Print();    
    vec.Delenie();  
    vec.Print();   
}
