#include <iostream>
#include <iomanip>

struct profile
{
    char name[25];
    int age;
    float point;
};


int main(void)
{
    int n;
    std::cout << "Number of student: ";
    std::cin >> n;
    std::cin.ignore(1);

    profile *student = (profile*)malloc(n*sizeof(profile));
    int i;

    // in stream
    for (i = 0; i < n; i++)
    {
        std::cout << "Number: " << i + 1 << "\n";
        std::cout << "Name: ";
        std::cin.get(student[i].name, 25);
        // ignore '/n' in the last of in stream when std::sin >> is used
        std::cin.ignore(1);
        std::cout << "Age: ";
        std::cin >> student[i].age;
        std::cin.ignore(1);
        std::cout << "Point: ";
        std::cin >> student[i].point;
        std::cin.ignore(1);
    }

    // out stream

    // std::setprecision(x)
    // set number of digits after decimal point, effective until a new format statement is encountered
    std::cout << std::setiosflags(std::ios::showpoint) << std::setprecision(2);
    // std::setw(8)
    // set minimum width for a field, effective only for a value printed immediately after
    std::cout << std::setw(18) << "Name" << std::setw(8) << "Age" << std::setw(8) << "Point" << '\n';

    for (i = 0; i < n; i++)
    {
        std::cout << std::setw(18) << student[i].name << std::setw(8) << student[i].age << std::setw(8) << student[i].point << '\n';
    }

    free(student);

    return 0;
}
