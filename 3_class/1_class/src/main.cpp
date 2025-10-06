#include <iostream>

/*
class name {
    // attributes
    // methods
};
// method definitions
*/

// attributes: 'name *A;' is approved, 'name A;' is not
// keyword private and public in definitions, default is private if keyword is missing
//      private: used only inside the class, generally used for attributes
//      public: use both inside and outside the class, generally used for methods

/*
name object1, object2;
*/

// each object after declaration will be allocated its own memory area to store its properties
// methods will be shared by all objects of the same class

class pixel {
    private:
    int x, y, colour;
    public:
    void pixelEnter(void);
    void pixelDisplay(void) {
        std::cout << "Pixel: [" << x << ',' << y << "], colour --" << colour << std::endl;

        return;
    }
    void pixelHide(void) {
        std::cout << "Pixel have been hidden" << std::endl;

        return;
    }
};

void pixel::pixelEnter(void) {
    std::cout << "Enter x, y: ";
    std::cin >> x >> y;
    std::cin.ignore(1);
    std::cout << "Enter colour: ";
    std::cin >> colour;
    std::cin.ignore(1);

    return;
}

int main(void) {
    pixel p1, p2;

    std::cout << "sizeof(class pixel) = sizeof(pixel::attributes) = 3 * sizeof(int) = " << sizeof(pixel) << std::endl;
    std::cout << "sizeof(p1) = " << sizeof(p1) << std::endl;
    std::cout << "sizeof(p2) = " << sizeof(p2) << std::endl;

    p1.pixelEnter();
    p1.pixelDisplay();

    p2.pixelHide();

    return 0;
}
