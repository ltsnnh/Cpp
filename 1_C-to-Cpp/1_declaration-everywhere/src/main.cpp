// header of C
// in C++, they are still available through libraries inherited from C
#include <stdio.h>
#include <stdlib.h>


// when entering a frame, all variables in that frame will be declared with a garbage value
// they will only be initialized when the program runs to the line where they are actually declared

int main(void) {
    // declare n and array, n and array will be get garbage values
    int n;
    printf("Enter number of elements: ");
    // get value of n
    scanf("%d", &n);

    // initialize value of array
    int *array = (int*)malloc(n*sizeof(int));

    //declare i (NOTE: scope and lifetime of i)
    for (int i = 0; i < n; i++) {
        printf("Enter value of number %d: ", i+1);
        scanf("%d", array + i);
    }

    printf("Array entered: ");
    //declare i again (NOTE: scope and lifetime of i)
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
