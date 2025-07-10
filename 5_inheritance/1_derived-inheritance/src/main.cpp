#include <iostream>

// BASE CLASS
class point {
    private:
    float x;
    float y;

    public:
    point(void) {
        this->x = this->y = 0;
    }

    point(float a, float b) {
        this->x = a;
        this->y = b;
    }

    void printfPoint(void) {
        std::cout << "x = " << this->x << ", y = " << this->y << std::endl;
        return;
    }
};

// DERIVED CLASS
// inherited all components of the relevant base classes
// public base class: all public components of base class are also public components of derived class
// private base class: all public components of base class are also private components of derived class
// missing keyword [private/public] also means private
class circle : private point {
    // ATTRIBUTE INHERITANCE
    // all attributes of base classes are inherited in derived class
    // however in derived class, there are no access to attributes of base classes
    private:
    float r;

    // methods of derived class is only allowed to access its own attributes

    // METHOD INHERITANCE
    // all methods of base classes are inherited in derived class
    // except constructor, destructor, assignment operator
    public:
    circle(void) {
        this->r = 0;
    }

    // base class are often treated like an class component
    circle(float a, float x, float y) : point(x, y) {
        this->r = a;
    }

    void printfR(void) {
        this->printfPoint();
        std::cout << "r = " << r << std::endl;
        return;
    }
};

int main(void) {
    circle cir(2.2F, 1U, 2.34F);
    cir.printfR();

    return 0;
}
