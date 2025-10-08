#include <iostream>

// class template
template <class argType>
class List {
    private:
    argType *ptr;
    int n;

    public:
    List(int);
    argType& operator[](int i) {
        return ptr[i];
    }
};

template <class argType> List<argType>::List(int n) {
    ptr = new argType[n];
}

int main() {
    // use class template to declare a object with any data type
    // by declare, new command or constructor
    List <int> x(20);
    x[3] = 7;

    for (int i = 0; i < 10; i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}
