#include <iostream>

// declare and define function at the same time
void delay(int n = 1000)
{
    for (int i = 0; i < n; i++)
    {
        ;
    }

    return;
}

// function prototype
// default value argument always are placed last from left to right
void sCalculateCircle(float &s, float r, char *pi = "Pi", float n = 3.14);

int main(void)
{
    // call delay function without specific parameter: default value of argument used
    delay();
    std::cout << "Program has delayed 1000 ticks\n";
    // call delay function with specific parameter: value of parameter used
    delay(5000);
    std::cout << "Program has delayed 5000 ticks\n";

    float s = 0;
    sCalculateCircle(s, 10.6);
    std::cout << "S = " << s << '\n';

    // missing parameters in function calls must correspond to the last default parameters
    // correct function call:
    // sCalculateCircle(s, 10.6, "PiPiPi", 3.1416);
    // sCalculateCircle(s, 10.6, "PiPiPi");
    // sCalculateCircle(s, 10.6);
    // incorrect function call:
    // sCalculateCircle(s, 10.6, 3.1416);

    return 0;
}

// function definition
// no need to reassign to argument at function definition
void sCalculateCircle(float &s, float r, char *pi, float n)
{
    s = n*r*r;

    return;
}
