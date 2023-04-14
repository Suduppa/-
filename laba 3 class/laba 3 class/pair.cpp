#include "Pair.h"
using namespace std;
Pair::Pair() {
    first = 0;
    second = 0.0;
}

Pair::Pair(int f, double s) {
    first = f;
    second = s;
}

Pair::Pair(const Pair& other) {
    first = other.first;
    second = other.second;
}

int Pair::getFirst() const {
    return first;
}

double Pair::getSecond() const {
    return second;
}

void Pair::setFirst(int f) {
    first = f;
}

void Pair::setSecond(double s) {
    second = s;
}

Pair Pair::operator- (const Pair& other) const {
    int f = first - other.first;
    double s = second - other.second;
    return Pair(f, s);
}

Pair Pair::operator+ (int x) const {
    int f = first + x;
    double s = second;
    return Pair(f, s);
}

Pair Pair::operator+ (double x) const {
    int f = first;
    double s = second + x;
    return Pair(f, s);
}

Pair Pair::operator++ () {
    ++first;
    return *this;
}

Pair Pair::operator++ (int) {
    Pair temp(*this);
    ++first;
    return temp;
}

ostream& operator<< (ostream& out, const Pair& p) {
    out << p.first << " : " << p.second;
    return out;
}
istream& operator>>(istream& is, Pair& p) {
    double f, s;
    is >> f >> s;
    p.setFirst(f);
    p.setSecond(s);
    return is;
};
