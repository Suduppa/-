#pragma once
#include <iostream>

class Pair {
private:
    int first;
    double second;

public:
    Pair();
    Pair(int f, double s);
    Pair(const Pair& other);

    int getFirst() const;
    double getSecond() const;
    void setFirst(int f);
    void setSecond(double s);

    Pair operator- (const Pair& other) const;
    Pair operator+ (int x) const;
    Pair operator+ (double x) const;
    Pair operator++ ();
    Pair operator++ (int);

    friend std::ostream& operator<< (std::ostream& out, const Pair& p);
    friend std::istream& operator>> (std::istream& is, Pair& p);
};
