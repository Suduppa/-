#include "Header File.h"
int main()
{
    setlocale(LC_ALL, "rus");
    int x, y;
    Money a;
    cout << "�������� ������� ������. ����� ����: 1,2,5,10,50,100,500,1000,5000" << endl;
    cin >> x;
    cout << "������� ���������� �����" << endl;
    cin >> y;
    a.set_first(x);
    a.set_second(y);
    a.get_summ();
    return(0);
}