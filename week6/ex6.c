#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
{
    int status;
    int fd[2];
    pipe(fd);
    printf("Pipe created\n");

    pid_t id1 = fork();
    printf("First process forked\n");

    pid_t id2 = fork();
    printf("Second process forked\n");

    if (id1 != 0 && id2 != 0)
    {
        write(fd[1], &id2, sizeof(id2));
        printf("Parent writes second process pid\n");
        printf("Parent waits for state changes in second child\n");
        waitpid(id2, &status, WUNTRACED);
        printf("Parent gets changes in second child\n");
        exit(0);
    }
    else if (id1 == 0)
    {
        printf("Inside the first process\n");
        read(fd[0], &id2, sizeof(id2));
        printf("First process reads data from pipe\n");
        printf("First process sleeps\n");
        sleep(2);
        printf("First process sends signal to the second process\n");
        kill(id2, SIGSTOP);
        printf("Signal has been sent\n");
    }
    else if (id2 == 0)
    {
        printf("Second process works\n");
        while (1)
        {
            printf("Second process alive!\n");
            sleep(1);
        }
    }
    

}
