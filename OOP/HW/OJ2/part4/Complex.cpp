#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Complex::Complex(double Re, double Im) : Re(Re), Im(Im) {}
Complex::Complex(double Re) : Re(Re), Im(0) {}

const double zero = pow(10, -5);

bool isZero(double x)
{
    if (x < zero && x > -zero){
        return true;
    }
    return false;
}

Complex Complex::operator- ()
{
    return Complex(0, -Im);
}

Complex operator+ (const Complex &y, const Complex &x)
{
    return Complex(y.Re + x.Re, y.Im + x.Im);
}
Complex operator- (const Complex &y, const Complex &x)
{
    return Complex(y.Re - x.Re, y.Im - x.Im);
}
Complex operator* (const Complex &y, const Complex &x)
{
    double real = y.Re * x.Re - y.Im * x.Im;
    double imag = y.Re * x.Im + x.Re * y.Im;
    return Complex(real, imag);
}
Complex operator/ (const Complex &y, const Complex &x)
{
    double real = (y.Re * x.Re + y.Im * x.Im) / (x.Re * x.Re + x.Im * x.Im);
    double imag = (x.Re * y.Im - y.Re * x.Im) / (x.Re * x.Re + x.Im * x.Im);
    return Complex(real, imag);
}

Complex Complex::operator~ ()
{
    return Complex(Re, -Im);
}

double abs(const Complex& x)
{   
    return sqrt(x.Re*x.Re + x.Im*x.Im);
}

std::ostream& operator<<(std::ostream& out,const Complex &x)
{
    
    using namespace std;
    out << fixed << setprecision(2);
    if (isZero(x.Re) == false)
    {
        if (x.Im >= zero){
        out << x.Re << " + " << x.Im << "i";
        }
        else if (x.Im <= -zero){
            out << x.Re << " - " << -x.Im << "i";
        }
        else if (isZero(x.Im)){
            out << x.Re;
        }
    }
    if (isZero(x.Re))
    {
        if (isZero(x.Im))
        {
            out << "0.00";
        }
        else
        {
            out << x.Im << "i";
        }
    } 


    return out;
}

Complex operator"" i(unsigned long long Im) {
    //TODO: 返回一个Complex对象
    return {0, static_cast<double>(Im)};
}
Complex operator"" i(long double Im) {
    
    //TODO: 返回一个Complex对象
    return {0, static_cast<double>(Im)};
}