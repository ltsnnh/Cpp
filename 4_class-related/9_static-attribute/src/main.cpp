#include <iostream>

// static attribute is allocated a static memory
// it exists even when none of objects are existing
// it is shared for all objects (for class)

class A {
    private:
    int temp;
    // declare static attribute
    static int sum;
    // here it does not exist, no memory has been allocated

    public:
    A(int x1) {
        this->temp = x1;
    }

    void printfSum(void) {
        this->sum+= temp;
        std::cout << "temp = " << this->sum<< std::endl;
        return;
    }
};

// define static attribute
int A::sum = 123;
// here it has been allocated memory and initialized value
// NOTE: if not define static attribute will not exist
// the build process will report an error at the linker step: symbol not found

int main(void) {
    A x(3);
    x.printfSum();

    A y(5);
    y.printfSum();

    return 0;
}
