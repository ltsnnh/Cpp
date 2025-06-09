#include <iostream>
#include "common.h"

int main(void)
{
    int a = 10;
    // initial reference variable refering to a specific variable
    // reference variable is only a alias, not be allocate memory
    int &ra = a;
    a += 1;
    std::cout << "a = " << a << '\n';
    ra += 1;
    std::cout << "a = " << ra << '\n';

    // initial const reference variable refering to a specific variable
    const int &cra = a;
    std::cout << "cra = " << cra << '\n';
    // const reference variable does not allow changing the value of the memory it references
    // cra += 1;

    return 0;
}
