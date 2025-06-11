#include <iostream>

class pixel
{
    private:
    int x, y, colour;
    public:
    void pixelEnter(void);
    void pixelDisplay(void)
    {
        // putpixel(x, y, m);
        return;
    }
    void pixelHide(void)
    {
        // hidepixel(x, y, m);
        return;
    }
};

void pixel::pixelEnter(void)
{
    std::cout << "Enter x, y: ";
    std::cin >> x >> y;
    std::cin.ignore(1);
    std::cout << "Enter colour: ";
    std::cin >> colour;
    std::cin.ignore(1);

    return;
}

int main(void)
{
    pixel p1;
    // pointer points to object
    pixel *pp1 = &p1;

    // access via object
    p1.pixelEnter();
    // access via pointer
    pp1->pixelDisplay();
    pp1->pixelHide();

    return 0;
}
