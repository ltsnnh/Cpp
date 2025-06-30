#include <iostream>

// the destruction of an object occurs in the following two cases:
// free up memory: delete, free, .etc
// free local variables, arrays when exiting functions, methods

// if a destructor is not defined in a class
// a default destructor that does nothing is generated

class polynomial
{
    private:
    int degree;
    float *coefficient;

    public:
    polynomial(void) {
        this->degree = 0;
        this->coefficient = NULL;
    }

    polynomial(int d) {
        this->degree = d;
        this->coefficient = new float[d + 1];
    }

    polynomial(const polynomial &existObject) {
        this->degree = existObject.degree;
        this->coefficient = new float[existObject.degree + 1];
        for (int i = 0; i <= existObject.degree; i++) {
            this->coefficient[i] = existObject.coefficient[i];
        }
    }

    // destructor
    ~polynomial(void) {
        this->degree = 0;
        delete this->coefficient;
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
        if (0 == this->degree) {
            std::cout << "No polynomial" << std::endl;
        }
        else {
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

    }
};

int main(void)
{
    // declare array of objects
    // call to the non-argument constructor to declare elements of array
    polynomial y[5];

    // declare and define array of objects
    // call to the argument constructor to initialize elements of array
    polynomial z[3] = {polynomial(3), polynomial(4), polynomial(2)};

    for (int i = 0; i < 3; i++) {
        z[i].enterPolynomial();
        std::cout << "z" << i << " = ";
        z[i].printPolynomial();
    }

    return 0;
}
