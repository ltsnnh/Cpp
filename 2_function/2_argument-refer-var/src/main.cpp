#include <iostream>

// reference variable is used as argument of function
// to save memory and reduce processing time by not having to create new variables
void sumCalculate(const float &ra, const float &rb, float &rc)
{
    rc = ra + rb;

    return;
}

int main(void)
{
    float c = 0;
    sumCalculate(1, 2, c);

    std::cout << "c = 1 + 2 = " << c << '\n';

    return 0;
}
