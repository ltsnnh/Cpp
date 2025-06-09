#include <iostream>

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
