#pragma once
#include <iostream>
using namespace std;
class book
{
    string name, author;
    int age;
public:
    book();
    book(string, string, int);
    book(const book&);
    ~book();
    string get_name();
    void set_name(string);
    string get_author();
    void set_author(string);
    int get_age();
    void set_age(int);
    void show();
};
