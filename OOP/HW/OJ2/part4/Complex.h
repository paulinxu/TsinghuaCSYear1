#pragma once
#include <iostream>

class Complex {
    public:
    double Re, Im;

    Complex(double Re, double Im);
    Complex(double Re);

    friend std::ostream& operator<<(std::ostream& out,const Complex &x);
    Complex operator~ ();

    Complex operator- ();

};

Complex operator+ (const Complex &y, const Complex &x);
Complex operator- (const Complex &y, const Complex &x);
Complex operator* (const Complex &y, const Complex &x);
Complex operator/ (const Complex &y, const Complex &x);

double abs(const Complex& x);

// //为虚数单位i定义字面量

Complex operator"" i(unsigned long long Im);
Complex operator"" i(long double Im);