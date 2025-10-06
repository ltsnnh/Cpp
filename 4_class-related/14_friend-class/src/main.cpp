#include <iostream>

// if class B is friend of class A
// all methods of class B can access to attribute of class A

// declare class
class A;
class B;
class C;

// definition class
class A {
    private:
    int x, y;

    public:
    void printfA(void) {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        return;
    }

    friend class B; // class B is friend of class A
    friend class C; // class C is friend of class A
};

class B {
    public:
    void enterA(A &arg) {
        std::cout << "Enter x, y of ARG" << std::endl;
        std::cin >> arg.x >> arg.y;
        std::cin.ignore(1);
        return;
    }

    friend class A;
    friend class C;
};

class C {
    friend class A;
    friend class B;
};

int main(void) {
    A tempA;
    B tempB;

    tempB.enterA(tempA);
    tempA.printfA();

    return 0;
}
