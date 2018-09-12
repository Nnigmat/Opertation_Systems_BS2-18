#include <stdio.h>
#include <sys/types.h>

void main()
{
    pid_t n = getpid(); 
    fork();
    if (n == getpid())
    {
        printf("Hello from parent [PID - %d]\n", n);
    }
    else
    {
        printf("Hello from child [PID - %d]\n", getpid());
    }
}
