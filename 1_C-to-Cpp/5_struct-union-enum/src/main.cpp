#include <iostream>
#include <iomanip>

// declare ~ typedef struct nameOfStruct in C
// also apply in union, enum
struct date_of_birth {
    unsigned short day;
    const char *month;
    unsigned short year;
};

struct worker {
    const char *name;
    date_of_birth birthday;
};

int main(void) {
    worker i;
    i.name = "Ltsnnh";
    i.birthday = {10, "Jun", 1997};
    std::cout << i.name << std::setw(5) << i.birthday.day << '-' << i.birthday.month << '-' << i.birthday.year << '\n';

    // enum
    enum week_day {SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY} today = week_day(1);
    // assignment a int value to enum var requires type casting

    switch (today) {
        case SUNDAY:
        std::cout << "today is SUNDAY" << '\n';
        break;
        case MONDAY:
        std::cout << "today is MONDAY" << '\n';
        break;
        case TUESDAY:
        std::cout << "today is TUESDAY" << '\n';
        break;
        case WEDSDAY:
        std::cout << "today is WEDSDAY" << '\n';
        break;
        case THURSDAY:
        std::cout << "today is THURSDAY" << '\n';
        break;
        case FRIDAY:
        std::cout << "today is FRIDAY" << '\n';
        break;
        case SATURDAY:
        std::cout << "today is SATURDAY" << '\n';
        break;
        default:
        break;
    }

    // union no name
    union {
        unsigned int u;
        unsigned short s[2];
        unsigned char c[4];
    };

    u = 0xFA88CA97;
    std::cout << std::hex << s[0] << " - " << std::hex << s[1] << '\n';
    std::cout << std::hex << (unsigned int)c[0] << " - " << std::hex << (unsigned int)c[1] \
        << " - " << std::hex << (unsigned int)c[2] << " - " << std::hex << (unsigned int)c[3] << '\n';

    return 0;
}
