#include <iostream>

// base - A <--- B <--- C <--- D - derived
class A {
    public:
    // VIRTUAL METHOD
    virtual void printClassName(void) {
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
    A *ptrA, *ptrB, *ptrC, *ptrD;
    A a;
    B b;
    C c;
    D d;

    ptrA = &a;
    ptrB = &b;
    ptrC = &c;
    ptrD = &d;
    // what method be called is decided at runtime
    ptrA->printClassName();
    ptrB->printClassName();
    ptrC->printClassName();
    ptrD->printClassName();

    // DYNAMIC BINDING
    // (the decision to call a function is made at runtime)
    // specify which method (among the methods with the same name of the inheritance relationship classes) is called
    // . depends on the specific object the pointer is pointing to

    return 0;
}
