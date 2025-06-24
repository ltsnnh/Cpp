#include <iostream>

// if a class have no constructor, the compiler will provide a default constructor without arguments
// the default constructor do no action

// if there is at least 1 constructor in the class, the default constructor will not be generated
// all commands that create new objects will call the class constructor

// should build both constructor with arguments and constructor without arguments

class pixel
{
    private:
    int x, y, colour;
    public:
    // constructor without arguments
    pixel(void) {
        x = y = 0;
        colour = 1;
    }
    // constructor with arguments
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
    // the program will allocate memory for the object first, then call the constructor
    // call to no argument constructor
    pixel a;
    std::cout << a.testSum() << std::endl;

    // call to argument constructor
    pixel b(2, 3, 18);
    std::cout << b.testSum() << std::endl;

    return 0;
}
