#include <iostream>

// static polymorphism achieves polymorphic behavior during compile time using function overloading and templates
// instead of relying on runtime information like dynamic polymorphism does

/*
template allows you to write a function or class without specifying a specific data type
when used, the compiler will create a specific version based on the data type you pass in
when to use templates?
- when you want to write reusable code for multiple data types
- when writing containers (like std::vector, std::map, … in STL)
- when writing generic algorithms (like std::sort, std::find)
*/

// template function to print any type
template<typename T>
void print(const T &value) {
    std::cout << "Printing value: " << value << std::endl;
}

int main() {
    print(42);          // int
    print(3.14159);     // double
    print("Hello");     // const char*

    return 0;
}
