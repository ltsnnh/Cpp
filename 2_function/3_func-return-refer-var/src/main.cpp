#include <iostream>

void func1(void);
void func2(void);
void func3(void);
void func4(void);

void (&keymap(const int &rkey))(void)
{
    switch (rkey)
    {
        case 1:
        return func1;
        break;
        case 2:
        return func2;
        break;
        case 3:
        return func3;
        break;
        case 4:
        return func4;
        break;
    }
}

int main(void)
{
    int key;
    std::cout << "Enter a number 1 - 4: ";
    std::cin >> key;
    std::cin.ignore(1);

    void(&rFuncPtr)(void) = keymap(key);
    rFuncPtr();

    return 0;
}

void func1(void)
{
    std::cout << "1.\n";
    return;
}
void func2(void)
{
    std::cout << "2.\n";
    return;
}
void func3(void)
{
    std::cout << "3.\n";
    return;
}
void func4(void)
{
    std::cout << "4.\n";
    return;
}
