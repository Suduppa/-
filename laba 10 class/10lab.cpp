
#include "Time.h"
#include <iostream>
#include <fstream>
#include "file_work.h"
#include <windows.h> 
using namespace std;
void main()
{
    setlocale(LC_ALL, "Russian");
 
    Time p, p1, p2;
    int k, c;
    char file_name[30];
    do
    { 
        cout << "\n1. Создать файл";
        cout << "\n2. Вывести файл";
        cout << "\n3. Удалить запись из файла";
        cout << "\n4. Добавить запись в файл";
        cout << "\n5. Изменить запись в файле";
        cout << "\n0. Выход\n";
        cin >> c;
        switch (c)
        {
        case 1: cout << "Имя файла?"; cin >> file_name;
            k = make_file(file_name);
            if (k < 0)cout << "Невозможно создать файл";
            break;
        case 2: cout << "Имя файла?"; cin >> file_name;
            k = print_file(file_name);
            if (k == 0)cout << "Пустой файл\n";
            if (k < 0)cout << "Невозможно прочесть файл\n";
            break;
        case 3: cout << "Имя файла?"; cin >> file_name;
            int nom; cout << "nom?"; cin >> nom;
            k = del_file(file_name, nom);
            if (k < 0)cout << "Невозможно прочесть файл";
            break;
        case 4: cout << "Имя файла?";
            cin >> file_name;
            cout << "nom?"; cin >> nom;
            cout << "Новый человек:";
           
            k = add_file(file_name, nom, p1);
          
            break;
        case 5: cout << "Имя файла?";
            cin >> file_name;
            cout << "nom?"; cin >> nom;
            cout << "Новое время:";
   
            cin >> p2;
            k = change_file(file_name, nom, p2);
            if (k < 0) cout << "\nНевозможно прочесть файл";
            if (k == 0) cout << "\nНет такой записи";
            break;
        }
    } while (c != 0);
}