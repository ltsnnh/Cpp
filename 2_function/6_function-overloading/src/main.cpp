#include <iostream>

// static polymorphism
// also known as compile-time polymorphism
// is a type of polymorphism that resolves the types and method calls at compile time rather than at runtime
// this is commonly achieved through the use of function overloading and templates

// function overloading
// when compiling, it will be based on the differences between arguments (type or quantity)
int sumCalculate(int a, int b);
float sumCalculate(float a, float b);

int main(void) {
    // when function is called, it will be based on the differences between parameter sets
    // when no function has an argument set of the same type as the parameter set
    // the compiler will choose the function with the closest argument type
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

int sumCalculate(int a, int b) {
    return (a+b);
}
float sumCalculate(float a, float b) {
    return (a+b);
}
