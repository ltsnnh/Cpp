#include <iostream>

// friend function
// differs from a normal function in that it can access class attributes

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
        return;
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
        return;
    }

    // friend function prototype
    friend void printfDegree(polynomial arg);
    // friend function declare and definition
    friend void printfCoefficient(polynomial arg) {
        if (NULL == arg.coefficient) {
            std::cout << "NULL!" << std::endl;
        }
        else {
            std::cout << "[ ";
            for (int i = 0; i <= arg.degree; i++) {
                std::cout << arg.coefficient[i];
                if (i == arg.degree) {
                    std::cout << " ]" << std::endl;
                }
                else {
                    std::cout << ", ";
                }
            }
        }
    }
};

// friend function definition
void printfDegree(polynomial arg) {
    std::cout << "Degree = " << arg.degree << std::endl;
    return;
}

int main(void)
{
    polynomial x(3);
    // use friend function
    printfDegree(x);

    x.enterPolynomial();
    // use friend function
    printfCoefficient(x);

    return 0;
}
