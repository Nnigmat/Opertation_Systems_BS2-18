#include <stdio.h>

void triangle(int n)
{
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

void half_of_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}

void rhombus(int n)
{
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    if (n % 2 != 0)
    {
        for (int i = 0; i <= n / 2; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n / 2; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void rectangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main() 
{
    int n, type;
    printf("Enter number of layers and type of figure (triangle - 0, half of triangle - 1, rhombus - 2, rectangle - 3): ");
    scanf("%d %d", &n, &type);

    switch(type)
    {
        case 0:
            triangle(n);
            break;
        case 1:
            half_of_triangle(n);
            break;
        case 2:
            rhombus(n);
            break;
        case 3:
            rectangle(n);
            break;
        default:
            printf("Sorry, invalid type");
    }

    return 0;
}
