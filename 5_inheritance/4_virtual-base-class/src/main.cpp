#include <iostream>

class A {
    public:
    int a;

    void printfA(void) {
        std::cout << "a = " << this->a << std::endl;
    }
};
/*
// can not declare twice a class as base classes of a derived class

class B : public A, public A {
    ;
};
*/

/*
// a class can be declared as base class of intermediate base classes for a derived class
// however, when calling the properties of the base class
// the compiler cannot recognize which base class property is being called

class B : public A {
    public:
    int b;
};

class C : public A {
    public:
    int c;
};

class D : public B, public C {
    public:
    int d;
};

int main(void) {
    D h;
    h.d = 0;
    h.c = 1;
    h.b = 2;
    h.a = 3;    // error : member found by ambiguous name lookup

    return 0;
}
*/

// virtual base class
class B : virtual public A {
    public:
    int b;
};

// virtual base class
class C : virtual public A {
    public:
    int c;
};

// virtual base classes will be combined to a single base class for any classes derived from them
class D : public B, public C {
    public:
    int d;
};

int main(void) {
    D h;
    h.d = 0;
    h.c = 1;
    h.b = 2;
    h.a = 3;    // call to a virtual base class

    h.A::printfA();

    return 0;
}
