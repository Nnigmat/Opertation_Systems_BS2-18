#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1]) 
            {
               int temp;
               temp = array[j];
               array[j] = array[j + 1];
               array[j + 1] = temp;
            } 
        }
    }
}

void main()
{
    int length = 10;
    int array[10] = {4,5,1,11,5,1,4,3, 2,10};
    bubble_sort(array, length);
    
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
}

