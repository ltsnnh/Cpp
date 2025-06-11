#include <iostream>

// function overloading
// when compiling, it will be based on the differences between the type of arguments
int sumCalculate(int a, int b);
float sumCalculate(float a, float b);

int main(void)
{
    // when function is called, it will be based on the differences between the type of parameter
    // should use type casting in function calls
    int m = sumCalculate(1, 2);
    float n = sumCalculate(1.1F, 2.2F);

    std::cout << "m = " << m << std::endl;
    std::cout << "n = " << n << std::endl;

    // get address of the overloading functions
    int (*pfm)(int, int) = sumCalculate;
    float (*pfn)(float, float) = sumCalculate;

    // type casting (void*) is required when printing function addresses
    std::cout << "address of sumCalculate int = " << (void*)pfm << std::endl;
    std::cout << "address of sumCalculate float = " << (void*)pfn << std::endl;

    return 0;
}

int sumCalculate(int a, int b)
{
    return (a+b);
}
float sumCalculate(float a, float b)
{
    return (a+b);
}
