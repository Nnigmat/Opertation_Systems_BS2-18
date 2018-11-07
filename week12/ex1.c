#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *random = fopen("/dev/random", "r");
    if (random == NULL)
    {
        printf("dev random can't be opened");
        exit(1);
    }

    FILE *dest = fopen("ex1.txt", "w+");
    if (dest == NULL)
    {
        printf("ex1.txt can't be opened");
        exit(1);
    }

    char str[20];
    fgets(str, 20, random);
    fputs(str, dest);

    fclose(random);
    fclose(dest);
    return 0;
}
