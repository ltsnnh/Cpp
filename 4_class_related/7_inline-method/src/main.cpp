#include <iostream>

// there are 2 ways to compile a method with inline
// - method definition inside class definition
// - add 'inline' keyword before method definition

// inline is just a suggestion to the compiler, not a command
// methods will generally not be inlined if they contain static variables, cyclic or branching statements, recursive functions, etc.

class polynomial
{
    private:
    int degree;
    float *coefficient;

    public:
    // inline
    polynomial(void) {
        this->degree = 0;
        this->coefficient = NULL;
    }

    // inline
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

    // inline
    ~polynomial(void) {
        this->degree = 0;
        delete this->coefficient;
    }

    const polynomial &operator=(const polynomial &source) {
        this->degree = source.degree;
        for (int i = 0; i <= source.degree; i++) {
            this->coefficient[i] = source.coefficient[i];
        }

        return source;
    }

    void enterPolynomial(void);

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

// not inline function
// in the function body contains the for statement
inline void polynomial::enterPolynomial(void) {
    std::cout << "Enter factors: " << std::endl;
    for (int i = 0; i <= degree; i++) {
        std::cout << "Enter factor of x^" << degree - i << ":";
        std::cin >> this->coefficient[i];
        std::cin.ignore(1);
    }
}

int main(void)
{
    polynomial *y = new polynomial(3);
    y->enterPolynomial();
    std::cout << "y: ";
    y->printPolynomial();

    polynomial z1 = *y;
    std::cout << "z1: ";
    z1.printPolynomial();

    polynomial z2(3);
    z2 = *y;
    std::cout << "z2: ";
    z2.printPolynomial();

    return 0;
}
