#include <iostream>
#include <math.h>

// static method is generally used to access static attribute
// it cannot access non-static attribute

class vertex {
    private:
    float x, y;

    public:
    void vertexEnter(void) {
        std::cout << "Enter x, y: ";
        std::cin >> x >> y;
        std::cin.ignore(1);

        return;
    }

    void vertexDisplay(void) {
        std::cout << "x = " << x << " y = " << y << std::endl;

        return;
    }

    float vertexSide(vertex B) {
        return sqrt(pow(this->x - B.x, 2) + pow(this->y - B.y, 2));
    }
};

class triangle {
    private:
    vertex a, b, c;

    public:
    // static method
    // no implicit argument this pointer
    // not associated with any particular object of the class
    static triangle creatTriangle(vertex A, vertex B, vertex C) {
        triangle t;

        t.a = A;
        t.b = B;
        t.c = C;

        return t;
    }
};

int main(void) {
    vertex a, b, c;
    triangle t;

    a.vertexEnter();
    b.vertexEnter();
    c.vertexEnter();

    // method call using class_name::static_method
    t = triangle::creatTriangle(a, b, c);

    return 0;
}
