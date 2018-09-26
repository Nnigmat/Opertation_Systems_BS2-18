#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
    pid_t id = fork();

    // Child process
    if (id == 0)
    {
        while (1)
        {
            printf("I'm alive\n");
            sleep(1);
        }
    }
    // Parent process
    else
    {
        sleep(10);
        kill(id, SIGTERM);
    }

}
