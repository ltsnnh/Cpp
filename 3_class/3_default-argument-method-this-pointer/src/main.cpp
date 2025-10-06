#include <iostream>

class pixel {
    private:
    int x, y, colour;
    public:
    void pixelEnter(void);
    void pixelDisplay(void) {
        std::cout << "Pixel: [" << this->x << ',' << this->y << "], colour --" << this->colour << std::endl;

        return;
    }
    void pixelHide(void) {
        std::cout << "Pixel have been hidden" << std::endl;

        return;
    }
};

// a method always has at least one argument, the this pointer
// and it is the first argument of the method
// the parameter passed to the this pointer is the address of the object associated with the method in the method call
void pixel::pixelEnter(void) {
    std::cout << "Enter x, y: ";
    std::cin >> this->x >> this->y;
    std::cin.ignore(1);
    std::cout << "Enter colour: ";
    std::cin >> this->colour;
    std::cin.ignore(1);

    return;
}

int main(void) {
    pixel p1;

    // method call
    // this (argument) = &p1 (parameter)
    p1.pixelEnter();
    p1.pixelDisplay();
    p1.pixelHide();

    return 0;
}
