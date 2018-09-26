#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void main()
{
    int buf_size = 128;
    char contain_text[] = "I contain text", empty[buf_size];
    pid_t id;

    int fd[2];
    if (pipe(fd) == 0)
    {
        // We are inside the child process
        if ((id = fork()) == 0)
        {
            write(fd[1], contain_text, strlen(contain_text));
        }
        // We in main process
        else
        {
            read(fd[0], empty, buf_size);
            printf("%s\n", empty);
        }
    }
}
