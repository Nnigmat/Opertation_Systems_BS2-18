#include <stdlib.h>

void* realloc_please(void* ptr, int size)
{
    if (ptr == NULL)
    {
        return malloc(size);
    }
    else if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        free(ptr);
        return malloc(size);
    }
}

void main()
{
    int *a = malloc(10);
    realloc_please(a, 15);
}
