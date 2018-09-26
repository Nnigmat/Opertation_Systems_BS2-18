#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void main()
{
    int buf_size = 128;
    char contain_text[] = "I contain text", empty[buf_size];

    int fd[2];
    if (pipe(fd) == 0)
    {
        write(fd[1], contain_text, strlen(contain_text));
        read(fd[0], empty, buf_size);
        printf("%s", empty);
    }
}
