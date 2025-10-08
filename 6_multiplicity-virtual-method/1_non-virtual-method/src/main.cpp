#include <iostream>

// base - A <--- B <--- C <--- D - derived
class A {
    public:
    // NON-VIRTUAL METHOD
    void printClassName(void) {
        std::cout << "Class A" << std::endl;
    }
};

class B : public A {
    public:
    void printClassName(void) {
        std::cout << "Class B" << std::endl;
    }
};

class C : public B {
    public:
    void printClassName(void) {
        std::cout << "Class C" << std::endl;
    }
};

class D : public C {
    public:
    void printClassName(void) {
        std::cout << "Class D" << std::endl;
    }
};


int main(void) {
    D clearlyCalling;
    // the call is from the object and specifies clearly the method to be called
    clearlyCalling.printClassName();
    clearlyCalling.C::printClassName();
    clearlyCalling.B::printClassName();
    clearlyCalling.A::printClassName();

    std::cout << "--------------------" << std::endl;

    A *ptrA, *ptrB, *ptrC, *ptrD;
    A a;
    B b;
    C c;
    D d;
    // base class pointer can be used to get address of derived class objects
    ptrA = &a;
    ptrB = &b;
    ptrC = &c;
    ptrD = &d;
    // the compiler decides at compile time
    ptrA->printClassName();
    ptrB->printClassName();
    ptrC->printClassName();
    ptrD->printClassName();

    // STATIC BINDING
    // (the decision to call a function is made at compile time)
    // specify which method (among the methods with the same name of the inheritance relationship classes) is called
    // 1. if the call comes from an object of a class, then the method of that class will be called
    // 2. if the call comes from a pointer, then the method of a class being same type with pointer will be call

    return 0;
}
