#include "Header File.h"
int main()
{
    setlocale(LC_ALL, "rus");
    int x, y;
    Money a;
    cout << "Выберите номинал купюры. Может быть: 1,2,5,10,50,100,500,1000,5000" << endl;
    cin >> x;
    cout << "Введите количество купюр" << endl;
    cin >> y;
    a.set_first(x);
    a.set_second(y);
    a.get_summ();
    return(0);
}