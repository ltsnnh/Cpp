#include <iostream>

// inline function
// inline is just a suggestion to the compiler, not a command
// functions will generally not be inlined if they contain static variables, cyclic or branching statements, recursive functions, etc.
// the inline keyword must appear before the function call
inline int errorHandle(unsigned int a, unsigned int b) {
    return a & b;
}

int main(void) {
    std::cout << "Return " << errorHandle(1, 2) << '\n';

    return 0;
}
