#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int isappend = 0;
    int isfile[argc], file_count = 0;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"-a") == 0)
        {
            isappend = 1;
            isfile[i] = 0;
            file_count++;
        }
        else if (strcmp(argv[i], "./a.out") != 0)
        {
            isfile[i] = 1;
            file_count++;
        }
        else
        {
            isfile[i] = 0;
            file_count++;
        }
    }
    
    if (file_count == 0)
    {
        printf("No files specified");
        exit(1);
    }

    char str[1024];
    fgets(str, 1024, stdin);

    for (int i = 0; i < argc; i++)
    {
        if (isfile[i])
        {
            FILE *file;

            if (isappend)
                file = fopen(argv[i], "a+");
            else
                file = fopen(argv[i], "w+");

            fputs(str, file);
        }
    }

    fputs(str, stdout);

    return 0;
}
