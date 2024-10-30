#pragma once
#include <ostream>

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

class Fraction
{
    public:
    int numerator;
    int denominator = 1;
    Fraction(int num) : numerator(num){}

    
    Fraction operator+(Fraction other)
    {
        numerator = (numerator*other.denominator + denominator*other.numerator);
        denominator = (denominator * other.denominator);

        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        return *this;
    }
    Fraction operator-(Fraction other)
    {
        numerator = (numerator*other.denominator - denominator*other.numerator);
        denominator = (denominator * other.denominator);
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        return *this;
    }
    Fraction operator*(Fraction other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }
        return *this;
    }
    Fraction operator/(Fraction other)
    {
        numerator *= other.denominator;
        denominator *= other.numerator;

        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0)
        {
            denominator = -denominator;
            numerator = -numerator;
        }

        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const Fraction& x){
    if (x.denominator == 1)
    {
        out << x.numerator;
    }
    else{
        out << x.numerator << '/' << x.denominator;
    }
	return out;
}