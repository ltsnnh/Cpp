#include <stdio.h>

int main(void) {
    int n = 5;
    float d1 = 0.0, d2 = 0.0;

    for (int i = 1; i < n; i++) {
        // C style for type casting: (type)expressions
        d1 += ((float)i+1)/(float)i;
        // C++ style for type casting: type(expressions)
        d2 += float(i+1)/float(i);
    }

    printf("d1 = %f = d2 = %f\n", d1, d2);

    return 0;
}
