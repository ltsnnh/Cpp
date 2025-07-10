#include <iostream>

// BASE CLASS
class point {
    private:
    float x;
    float y;


    // protected attributes
    // access scope can only be extended to classes directly derived from this class
    protected:
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
        return;
    }
};

// DERIVED CLASS
// public base class: all public and protected components of base class are also public and protected components of derived class
// private base class: all public and protected components of base class are also private components of derived class
class circle : private point {
    private:
    float r;
    char *circleName;

    public:
    circle(void) {
        this->r = 0;
    }

    circle(float a, float x, float y) : point(x, y) {
        this->r = a;
        this->circleName = new char[22];
        std::cout << "Enter the name of circle: ";
        std::cin >> this->circleName;
        std::cin.ignore(1);
    }

    ~circle(void) {
        delete this->circleName;
    }

    void printfR(void) {
        this->printfPoint();
        // use base class components in derived class
        std::cout << "Name of point: " << this->pointName << std::endl;
        std::cout << "r = " << r << std::endl;
        std::cout << "Name of circle: " << this->circleName << std::endl;
        return;
    }
};

int main(void) {
    circle cir(2.2F, 1U, 2.34F);
    cir.printfR();

    return 0;
}
