#include <iostream>

// if a class have no constructor, the compiler will provide a default constructor without arguments
// the default constructor do no action

// if there is at least 1 constructor in the class, the default constructor will not be generated
// all commands that create new objects will call the class constructor

// should build both constructor with arguments and constructor without arguments

// using constructors to create complete objects is convenient
// because it avoids extra operations (like memory allocation, .etc)

class polynomial
{
    private:
    int degree;
    float *coefficient;
    public:
    // constructor without arguments
    polynomial(void) {
        this->degree = 1;
        this->coefficient = NULL;
    }
    // constructor with arguments
    polynomial(int d);
};

polynomial::polynomial(int d) {
    this->degree = d;
    this->coefficient = new float[d + 1];
}

int main(void)
{
    // the program will allocate memory for the object first, then call the constructor
    // call to no argument constructor
    polynomial a;

    // call to argument constructor
    polynomial b(3);

    return 0;
}
