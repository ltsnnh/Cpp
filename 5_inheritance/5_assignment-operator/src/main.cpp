#include <iostream>

// when derived class have pointer attributes
// including attributes inherited from base classes and component classes
// do not use default assignment operator
// must use derived assignment operator

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

    // first: build up the assignment operator for base class
    const point &operator=(const point &source) {
        this->x = source.x;
        this->y = source.y;
        for (int i = 0; i <= 21; i++) {
            this->pointName[i] = source.pointName[i];
        }

        return source;
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

    // last: build up the assignment operator for derived class
    const circle &operator=(const circle &source) {
        this->r = source.r;
        for (int i = 0; i <= 21; i++) {
            this->circleName[i] = source.circleName[i];
        }

        // to use assignment operator of base class, need to cast the type follow pattern:
        *((point*)this) = point::operator=(source);
        // point(*this) = point::operator=(source);

        return source;
    }

    void printfR(void) {
        this->printfPoint();
        std::cout << "r = " << r << std::endl;
        std::cout << "Name of circle: " << this->circleName << std::endl;
        return;
    }
};

int main(void) {
    circle cir1(2.2F, 1U, 2.34F);
    cir1.printfR();

    circle cir2(10.F, 10U, 10.F);
    cir2 = cir1;
    cir2.printfR();

    return 0;
}
