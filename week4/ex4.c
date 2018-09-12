#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

int in_background(char * command)
{
    int ends_with_ampersand = FALSE, index;
    for (int i = 0; i < strlen(command); i++)
    {
        if (command[i] == '&' || command[i] == ' ')
            ends_with_ampersand = TRUE;
        else
            ends_with_ampersand = FALSE;
    }
    return ends_with_ampersand;
}

void readline(char * line)
{
    char c = getc(stdin);
    int i = 0;
    while (c != '\n')
    {
        line[i] = c; 
        c = getc(stdin);
        i++;
    }
    line[i] = '\0';
}

void main()
{
    char command[30], *exit = "exit";
    command[29] = '\0';

    pid_t pid = getpid();
    
    do
    {
        printf("%: ");
        readline(command);
        if (strcmp(command, exit) == 0)
        {
            return;
        } 
        else if (in_background(command))
        {
            fork();        
            if (pid != getpid()) 
            {
                system(command);
                return;
            }
        }
        else 
        {
            system(command);
        }
    } while (1);

    return;
}
