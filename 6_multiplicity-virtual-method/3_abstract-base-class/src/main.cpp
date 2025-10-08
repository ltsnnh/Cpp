#include <iostream>

// base - A <--- B <--- C <--- D - derived

// ABSTRACT BASE CLASS
// must have at least a pure virtual function
class A {
    public:
    // PURE VIRTUAL METHOD
    virtual void printClassName() = 0;
};

// classes that inherit from abstract base classes must override pure virtual functions to create objects
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
    // cannot creat instance of abstract class
    // A a;
    // pointers and reference variables that to objects of abstract classes are still valid
    A *ptrA;

    B b;
    C c;
    D d;

    ptrA = &b;
    ptrA->printClassName();
    ptrA = &c;
    ptrA->printClassName();
    ptrA = &d;
    ptrA->printClassName();

    return 0;
}
