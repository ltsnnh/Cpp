#include <iostream>
#include <new>

void check_function_new(void) {
    std::cout << "Dynamic memory allocate pd2 error!";
    exit(0);
}

int main(void) {
    int *pd1, *pd2;
    int n;
    std::cout << "Number of element: ";
    std::cin >> n;
    std::cin.ignore(1);

    // *p = new --type
    // dynamic memory allocate for 1 element
    pd1 = new int;
    // checking method 1: If new fails to allocate memory, new function returns a NULL pointer
    if (NULL == pd1) {
        std::cout << "Dynamic memory allocate pd1 error!";
        exit(0);
    }

    // this function stores your handler function to the global function pointer _new_handler
    std::set_new_handler(check_function_new);
    // *p = new --type[n]
    // dynamic memory allocate for n elements
    pd2 = new int[n];
    // checking method 2: If new fails to allocate memory, it will call the _new_handler function

    std::cout << "Dynamic memory allocate successfully.\n";

    // ~ free(p) in C
    delete(pd1);
    delete(pd2);

    return 0;
}
