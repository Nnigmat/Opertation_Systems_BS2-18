#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char command[30], *exit = "exit";
    command[29] = '\0';
    
    do
    {
        printf("%: ");
        scanf("%s", command);
        if (command == exit)
        {
            system(command);
        } 
        else
        {
            return;
        }
    } while (1);
    return;
}
