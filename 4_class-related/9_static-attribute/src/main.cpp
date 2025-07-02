#include <iostream>

// static attribute is allocated a static memory
// it exists even when none of objects are existing
// it is shared for all objects (for class)

class A {
    private:
    // declare static attribute
    static int temp;
    // here it does not exist, no memory has been allocated

    public:
    A(int x1) {
        this->temp = x1;
    }

    void printfTemp(void) {
        std::cout << "temp = " << this->temp << std::endl;
        return;
    }
};

// define static attribute
int A::temp = 123;
// here it has been allocated memory and initialized value
// NOTE: if not define static attribute will not exist
// the build process will report an error at the linker step: symbol not found

int main(void)
{
    A x(3);
    x.printfTemp();

    A y(5);
    y.printfTemp();

    return 0;
}
