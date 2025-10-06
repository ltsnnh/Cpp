#include <iostream>

class A {
    private:
    int a, b;

    public:
    A(void) {
        a = b = 0;
    }

    A(int a1, int b1) {
        a = a1;
        b = b1;
    }
};

class B {
    private:
    float x, y, z;

    public:
    B(void) {
        x = y = z = 0.0;
    }

    B(float x1, float y1) {
        x = x1;
        y = y1;
        z = x1 + y1;
    }

    B(float x1, float y1, float z1) {
        x = x1;
        y = y1;
        z = z1;
    }
};

class C {
    private:
    int m, n;
    A u, v;
    B p, q, r;

    public:
    // the constructor of covering class
    // methods of covering class is not allow to access attributes of component class
    // the constructor of covering class must use constructors of component classes

    // objects initialized with non-argument constructors can be omitted
    C(int m1, int n1, int a1, int b1, float x1, float y1, float z1, float x2, float y2) \
    : u(), v(a1, b1), q(x1, y1, z1), r(x2, y2) {
        m = m1;
        n = n1;
    }
    // u is initialized with non-argument constructor
    // v is initialized with argument constructor
    // p(missing) is initialized with non-argument constructor
    // q is initialized with 2-argument constructor
    // r is initialized with 3-argument constructor
};

int main(void) {

    return 0;
}
