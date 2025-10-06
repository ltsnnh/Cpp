#include <iostream>

class polynomial {
    private:
    int degree;
    float *coefficient;

    public:
    polynomial(void) {
        this->degree = 1;
        this->coefficient = new float[1];
    }

    polynomial(int d) {
        this->degree = d;
        this->coefficient = new float[d + 1];
    }

    void enterPolynomial(void) {
        std::cout << "Enter factors: " << std::endl;
        for (int i = 0; i <= degree; i++) {
            std::cout << "Enter factor of x^" << degree - i << ":";
            std::cin >> this->coefficient[i];
            std::cin.ignore(1);
        }
    }

    void printPolynomial(void) {
        for (int i = 0; i <= degree; i++) {
            if (1 < (degree - i)) {
                if (1 == this->coefficient[i]) {
                    std::cout << "x^" << degree - i << " + ";
                }
                else {
                    std::cout << this->coefficient[i] << "x^" << degree - i << " + ";
                }
            }
            else if (1 == (degree - i)) {
                if (1 == this->coefficient[i]) {
                    std::cout << "x" << " + ";
                }
                else {
                    std::cout << this->coefficient[i] << "x" << " + ";
                }
            }
            else {
                std::cout << this->coefficient[i] << " = 0" << std::endl;
            }
        }
    }
};

int main(void) {
    polynomial y(3);

    y.enterPolynomial();
    std::cout << "y: ";
    y.printPolynomial();

    // call the default copy constructor (default method in C++)
    // default method will copy bit to bit corresponding of memory
    // when the class has no pointer or reference properties, using the default copy constructor is sufficient
    polynomial z(y);
    std::cout << "z: ";
    z.printPolynomial();

    // in this case using the default constructor can lead to errors
    // the goal is to create a new object that is similar to the old object, but independent of the old object
    // here, 2 objects have the attribute pointing to the same memory
    // when value of the memory area changes or is deleted, it will affect the remaining object
    y.enterPolynomial();
    std::cout << "y: ";
    y.printPolynomial();
    std::cout << "z: ";
    z.printPolynomial();

    return 0;
}
