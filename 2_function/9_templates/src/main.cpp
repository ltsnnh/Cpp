#include <iostream>

// static polymorphism achieves polymorphic behavior during compile time using function overloading and templates
// instead of relying on runtime information like dynamic polymorphism does

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
