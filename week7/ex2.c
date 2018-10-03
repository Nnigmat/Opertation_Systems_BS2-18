#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("Please, write size of array you want to allocate: ");

    int n;
    scanf("%d", &n);
    printf("\n");
    
    int *array = (int *) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        array[i] = i;
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);
}
