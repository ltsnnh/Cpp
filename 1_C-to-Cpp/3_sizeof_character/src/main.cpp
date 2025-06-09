#include <stdio.h>

int main(void)
{
    // in C, sizeof('A') = sizeof(int) = 4
    printf("sizeof('character') = sizeof(char) = %lu\n", sizeof('A'));

    return 0;
}
