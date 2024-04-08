////////////////////////////////////////////////////////
//CharLine.cpp
#define CRT_SECURE_NO_WARNINGS
#include "CharLine.h"
#include <string>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

CharLine::CharLine()
{
    N = 0;
    s = nullptr;
}

CharLine::CharLine(int y, const char* r)
{
    N = y;
    s = new char[N + 1];
    strcpy_s(s, N + 1, r);
}

CharLine::CharLine(const CharLine& r)
{
    N = r.N;
    s = new char[N + 1];  // Виділення нової пам'яті для копіювання даних
    strcpy_s(s, r.N + 1, r.s);  // Копіювання даних
}

CharLine::~CharLine()
{
    delete[] s;
}

void CharLine::setN(int value)
{
    N = value;
}

void CharLine::setS(const char* value)
{
    delete[] s;
    N = strlen(value);
    s = new char[N + 1];
    strcpy_s(s, N + 1, value);
}

CharLine& CharLine::operator =(const CharLine& r)
{
    // Перевірка на самоприсвоєння
    if (&r == this)
        return *this;

    // Встановлення нового значення N
    setN(r.getN());

    // Встановлення нового значення рядка
    setS(r.getS());

    return *this;
}

CharLine::operator string () const
{
    stringstream ss;
    ss << " Re = " << getN() << endl;
    ss << " Im = " << getS() << endl;
    return ss.str();
}




bool operator==(const CharLine& lhs, const CharLine& rhs) {
    if (lhs.getN() != rhs.getN()) {
        return false;
    }

    for (int i = 0; i < lhs.getN(); i++) {
        if (lhs.getS()[i] != rhs.getS()[i]) {
            return false;
        }
    }

    return true;
}
// Оператор "!="
bool operator!=(const CharLine& lhs, const CharLine& rhs) {
    return !(lhs == rhs);
}

// Оператор "<="
bool operator<=(const CharLine& lhs, const CharLine& rhs) {
    return !(rhs < lhs);
}

// Оператор ">="
bool operator>=(const CharLine& lhs, const CharLine& rhs) {
    return !(lhs < rhs);
}

// Оператор ">"
bool operator>(const CharLine& lhs, const CharLine& rhs) {
    return (rhs < lhs);
}

// Оператор "<"
bool operator<(const CharLine& lhs, const CharLine& rhs) {
    if (lhs == rhs) {
        return false;
    }
    int minLength = std::min(lhs.getN(), rhs.getN());
    for (int i = 0; i < minLength; i++) {
        if (lhs.getS()[i] < rhs.getS()[i]) {
            return true;
        }
        else if (lhs.getS()[i] > rhs.getS()[i]) {
            return false;
        }
    }
    return lhs.getN() < rhs.getN();
}



ostream& operator<<(ostream& out, const CharLine& a)
{
    return out << "Length = " << a.getN() << " String = " << a.getS();
}

istream& operator >>(istream& in, CharLine& a)
{
    cout << "N: "; in >> a.N;
    in.ignore();
    cout << "S: "; in.getline(a.s, a.N, '\n'); // Зчитати рядок довжиною a.N
    return in;
}



CharLine& CharLine::operator ++()
{
    setN(getN() + 1);
    return *this;
}

CharLine& CharLine::operator --()
{
    setN(getN() - 1);
    return *this;
}

CharLine CharLine::operator++(int)
{
    CharLine temp(*this);
    setN(getN() + 1);
    char* temp_s = new char[getN() + 1];
    strcpy_s(temp_s, getN() + 1, getS());
    temp_s[getN() - 1] = 'w';
    temp_s[getN()] = '\0';
    setS(temp_s);
    delete[] temp_s;
    return temp;
}

CharLine CharLine::operator--(int)
{
    CharLine temp(*this);
    if (getN() > 0) {
        setN(getN() - 1);
        char* temp_s = new char[getN() + 1];
        strcpy_s(temp_s, getN() + 1, getS());
        temp_s[getN()] = '\0';
        setS(temp_s);
        delete[] temp_s;
    }
    return temp;
}




char CharLine::operator[](int position)const
{
    if (position >= 0 && position < getN()) {
        return getS()[position];
    }
    else {
        cout << "Invalid position" << endl;
        return '\0';
    }
}


bool CharLine::operator()(char targetChar) {
    for (int i = 0; i < getN(); i++) {
        if (getS()[i] == targetChar) {
            return true;
        }
    }
    return false;
}

CharLine operator+(const CharLine& lhs, const CharLine& rhs) {
    CharLine result;
    result.setN(lhs.getN() + rhs.getN());
    char* temp_s = new char[result.getN() + 1];
    strcpy_s(temp_s, result.getN() + 1, lhs.getS());
    strcat_s(temp_s, result.getN() + 1, rhs.getS());
    result.setS(temp_s);
    delete[] temp_s;
    return result;
}

bool operator%(const CharLine& line, const CharLine& substring) {
    if (substring.getN() >= line.getN()) {
        return false;
    }

    for (int i = 0; i <= line.getN() - substring.getN(); i++) {
        bool match = true;
        for (int j = 0; j < substring.getN(); j++) {
            if (line.getS()[i + j] != substring.getS()[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }

    return false;
}


