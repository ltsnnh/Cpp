#include <iostream>
#include <iomanip>
#include "common.h"

// declare ~ typedef struct nameOfStruct in C
// also apply in union, enum
struct date_of_birth {
    unsigned short day;
    char *month;
    unsigned short year;
};

struct worker {
    char *name;
    date_of_birth birthday;
};

int main(void)
{
    worker i;
    i.name = "Ltsnnh";
    i.birthday = {10, "Jun", 1997};
    std::cout << std::setw(8) << i.name << std::setw(5) << i.birthday.day << '-' << i.birthday.month << '-' << i.birthday.year << '\n';

    // enum
    enum week_day {SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY} yesterday = week_day(1);
    // assignment a int value to enum var requires type casting
    week_day tomorrow = week_day(2);

    // union no name
    union
    {
        unsigned int u;
        unsigned short b[2];
    };

    u = 0xFA88CA97;
    std::cout << b[0] << " - " << b[1] << '\n';

    return 0;
}
