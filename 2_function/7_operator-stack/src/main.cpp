#include <iostream>

struct fraction
{
    int numerator;
    int denominator;
};

// operator is a keyword
fraction operator+(fraction a, fraction b);
fraction operator-(fraction a, fraction b);
fraction operator*(fraction a, fraction b);
fraction operator/(fraction a, fraction b);

std::ostream& operator<<(std::ostream& os, fraction p);
std::istream& operator<<(std::istream& is, fraction &p);

int main(void)
{
    fraction a = {1, 2};
    fraction b = {2, 3};

    // can use operator stack as a function
    fraction c1 = operator+(a, b);
    // or use as a operator
    fraction c2 = a + b;
    // can combine open and close parentheses
    fraction d1 = (a + b) * b;
    // still follow the order of priority
    fraction d2 = a + b * b;

    std::cout << "c1 = " << c1.numerator << '/' << c1.denominator << std::endl;
    std::cout << "c2 = " << c2.numerator << '/' << c2.denominator << std::endl;
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;

    return 0;
}

fraction operator+(fraction a, fraction b)
{
    fraction result;

    result.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
    result.denominator = a.denominator*b.denominator;

    return result;
}

fraction operator-(fraction a, fraction b)
{
    fraction result;

    result.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
    result.denominator = a.denominator*b.denominator;

    return result;
}

fraction operator*(fraction a, fraction b)
{
    fraction result;

    result.numerator = a.numerator*b.numerator;
    result.denominator = a.denominator*b.denominator;

    return result;
}

fraction operator/(fraction a, fraction b)
{
    fraction result;

    result.numerator = a.numerator*b.denominator;
    result.denominator = a.denominator*b.numerator;

    return result;
}

std::ostream& operator<<(std::ostream& os, fraction p)
{
    os << p.numerator << '/' << p.denominator;

    return os;
}

std::istream& operator<<(std::istream& is, fraction &p)
{
    std::cout << "Enter the numerator and the denominator";
    is >> p.numerator >> p.denominator;
    std::cin.ignore(1);

    return is;
}
