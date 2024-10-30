#pragma once
#include <iostream>
#include <string>

class Monomial
{
private:
    int coe;
    int deg;
public:
    Monomial();
    Monomial(int _c, int _d);
    Monomial operator+(const Monomial &x);
    Monomial operator-(const Monomial &x);
    Monomial operator*(const Monomial &x);
    Monomial operator/(const Monomial &x);
    int definite_integral(const int a, const int b);
    Monomial derive();
    int get_val(int x);
    //TODO
    friend std::istream& operator>>(std::istream& in, Monomial &x);
    friend std::ostream& operator<<(std::ostream& out,const Monomial &x);
    int getCoe();
    int getDeg();
    
};