#include <iostream>

class pixel
{
    private:
    int x, y, colour;
    public:
    // constructor
    // is also a method, with the same name as the class name
    // used to create a new object
    // the program will allocate memory for the object, then call the constructor to initialize value of attributes
    // the constructor name is the same class name, no type declared and no return value
    // constructor 1
    pixel(void) {
        x = y = 0;
        colour = 1;
    }
    // constructor 2
    pixel(int x1, int y1, int colour1 = 1);

    int testSum(void) {
        return (x * y + colour);
    }
};

pixel::pixel(int x1, int y1, int colour1) {
    x = x1;
    y = y1;
    colour = colour1;
}

int main(void)
{
    // use constructor in declaration
    // call to no argument constructor
    pixel a;
    std::cout << a.testSum() << std::endl;

    // call to argument constructor
    pixel b(2, 3, 18);
    std::cout << b.testSum() << std::endl;

    // call to have argument constructor
    pixel c(3, 4);
    std::cout << c.testSum() << std::endl;

    // call to no argument constructor
    pixel d[10];
    std::cout << d[1].testSum() << std::endl;

    // use constructor in dynamic allocate memory
    // call to no argument constructor
    pixel *p = new pixel;
    std::cout << p->testSum() << std::endl;

    // call to argument constructor
    pixel *q = new pixel(2, 3, 18);
    std::cout << q->testSum() << std::endl;

    // use constructors to represent constant objects
    // no argument constructor
    std::cout << pixel().testSum() << std::endl;
    // argument constructor
    std::cout << pixel(2, 3, 18).testSum() << std::endl;

    return 0;
}
