#include <iostream>
#include <cmath>

#include "Monomial.h"

using namespace std;

Monomial::Monomial() : coe(0), deg(0) {};

Monomial::Monomial(int _c, int _d){coe = _c; deg = _d;};

Monomial Monomial::operator+(const Monomial &x)
{
    if (deg != x.deg)
    {
        return Monomial(coe, deg); 
    }
    if (coe + x.coe == 0)
    {
        return Monomial(0, 0);
    }
    return Monomial(coe + x.coe, x.deg); 
};
Monomial Monomial::operator-(const Monomial &x)
{
    if (deg != x.deg)
    {
        return Monomial(coe, deg); 
    }
    if (coe - x.coe == 0)
    {
        return Monomial(0, 0);
    }
    return Monomial(coe - x.coe, x.deg); 
};
Monomial Monomial::operator*(const Monomial &x)
{
    if (coe * x.coe == 0)
    {
        return Monomial(0, 0);
    }
    return Monomial(coe * x.coe, deg + x.deg);
};
Monomial Monomial::operator/(const Monomial &x)
{
    if (coe / x.coe == 0)
    {
        return Monomial(0, 0);
    }
    return Monomial(coe / x.coe, deg - x.deg);
};
int Monomial::definite_integral(const int a, const int b)
{
    long u = int(coe/(deg+1)) * pow(b, deg+1);
    long d = int(coe/(deg+1)) * pow(a, deg+1);
    return u-d;
};
Monomial Monomial::derive()
{
    if (deg * coe == 0)
    {
        return Monomial(0, 0);
    }
    return Monomial(deg * coe, deg - 1);
};
int Monomial::get_val(int x)
{
    long ans = coe * pow(x, deg);
    return ans;
};
std::istream& operator>>(std::istream& in, Monomial &x)
{
    
    string text;
    in >> text;
    string coe;
    string deg;

    for (int i = 0 ; i < text.length(); i ++)
    {
        if (text[i] == 'x')
        {
            coe = text.substr(0, i);
            deg = text.substr(i+2);
            break;
        }
    }
    x.coe = std::stoi(coe);
    x.deg = std::stoi(deg);
    return in;
};

std::ostream& operator<<(std::ostream& out,const Monomial &x)
{
    cout << x.coe << "x^" << x.deg << endl;
    return out;
};
int Monomial::getCoe()
{
    return coe;
}
int Monomial::getDeg()
{
    return deg;
}
