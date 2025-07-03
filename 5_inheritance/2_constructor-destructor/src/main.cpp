#include <iostream>

// derived classes do not inherit constructors and destructors, assignment operators of base classes

// BASE CLASS
class point {
    private:
    float x;
    float y;
    char *pointName;

    public:
    point(void) {
        this->x = this->y = 0;
    }

    point(float a, float b) {
        this->x = a;
        this->y = b;
        this->pointName = new char[22];
        std::cout << "Enter the name of point: ";
        std::cin >> this->pointName;
        std::cin.ignore(1);
    }

    ~point(void) {
        delete this->pointName;
    }

    void printfPoint(void) {
        std::cout << "x = " << this->x << ", y = " << this->y << std::endl;
        std::cout << "Name of point: " << this->pointName << std::endl;
        return;
    }
};

// DERIVED CLASS
class circle : private point {
    private:
    float r;
    char *circleName;

    public:
    // CONSTRUCTOR
    circle(void) {
        this->r = 0;
    }

    // CONSTRUCTOR
    // initialize the new attributes of derived class
    // for attributes of base classes, use their constructors
    // for attributes of component objects, use their constructor
    circle(float a, float x, float y) : point(x, y) {
        this->r = a;
        this->circleName = new char[22];
        std::cout << "Enter the name of circle: ";
        std::cin >> this->circleName;
        std::cin.ignore(1);
    }

    // DESTRUCTOR
    // when a derived class object is freed, the component objects and dereived object of base class are also freed
    // only care about attributes, not component objects
    ~circle(void) {
        delete this->circleName;
    }

    void printfR(void) {
        this->printfPoint();
        std::cout << "r = " << r << std::endl;
        std::cout << "Name of circle: " << this->circleName << std::endl;
        return;
    }
};

int main(void) {
    circle cir(2.2, 1, 2.34);
    cir.printfR();

    return 0;
}
