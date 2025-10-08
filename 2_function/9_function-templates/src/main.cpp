#include <iostream>

// static polymorphism achieves polymorphic behavior during compile time using function overloading and templates
// instead of relying on runtime information like dynamic polymorphism does

/*
template allows you to write a function or a class with specific data types as arguments
when used, the compiler will create a specific function based on the data type you pass in
when to use templates?
- when you want to write reusable code for multiple data types
- when writing containers (like std::vector, std::map, … in STL)
- when writing generic algorithms (like std::sort, std::find)
*/

// template function to print any type
template <typename T>
void print(const T &value) {
    std::cout << "Printing value: " << value << std::endl;
}

// template function to get larger value number
template <class argType>
argType getLarger(argType x, argType y) {
    return (x > y) ? x : y;
}

int main() {
    print(42);          // int
    print(3.14159);     // double
    print("Hello\n");     // const char*

    std::cout << "Max = " << getLarger(6, 8) << std::endl;
    std::cout << "Max = " << getLarger(8.5, 6.3) << std::endl;

    return 0;
}
