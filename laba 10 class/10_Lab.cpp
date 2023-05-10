// Лабораторная работа №10, Вариант 2 (2 семестр).
//

//#include "Person.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include "file_work.h"
#include <windows.h>    // Библиотека для русской локализации
using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");

    //Person p, p1, p2;
    Time p, p1, p2;
    int k, c;
    char file_name[30];
    do
    { //Меню
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete record from file";
        cout << "\n4. Add record to file";
        cout << "\n5. Change record in file";
        cout << "\n0. Exit\n";
        cin >> c;
        switch (c)
        {
        case 1: cout << "file name?"; cin >> file_name;
            k = make_file(file_name);
            if (k < 0)cout << "Can't make file";
            break;
        case 2: cout << "file name?"; cin >> file_name;
            k = print_file(file_name);
            if (k == 0)cout << "Empty file\n";
            if (k < 0)cout << "Can't read file\n";
            break;
        case 3: cout << "file name?"; cin >> file_name;
            int nom; cout << "nom?"; cin >> nom;
            k = del_file(file_name, nom);
            if (k < 0)cout << "Can't read file";
            break;
        case 4: cout << "file name?";
            cin >> file_name;
            cout << "nom?"; cin >> nom;
            cin >> p1;
            k = add_file(file_name, nom, p1);
            break;
        case 5: cout << "file name?";
            cin >> file_name;
            cout << "nom?"; cin >> nom;
            cout << "New Time:";
            //Person p2;
            cin >> p2;
            k = change_file(file_name, nom, p2);
            if (k < 0) cout << "\nCan't read file";
            if (k == 0) cout << "\nNot such record";
            break;
        }
    } while (c != 0);
}