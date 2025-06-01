#include <stdio.h>
#include <math.h>
#include "common.h"

int main(void)
{
    // declare n
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // declare *array
    int *array = (int*)malloc(n*sizeof(int));

    //declare i (NOTE: scope and lifetime of i)
    for (int i = 0; i < n; i++)
    {
        printf("Enter value of number %d: ", i+1);
        scanf("%d", array + i);
    }

    printf("Array entered: ");
    //declare i again (NOTE: scope and lifetime of i)
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
