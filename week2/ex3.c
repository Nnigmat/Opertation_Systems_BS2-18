#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int line_length = n * 2 - 1;

    for (; n > 0; n--)
    {
        int i = 0;
        for (; i < (n - 1); i++)
        {
            printf(" ");
        }

        for (i = line_length - i * 2; i > 0; i --)
        {
            printf("*");
        }

        printf("\n");
    }
}
