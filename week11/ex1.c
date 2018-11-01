#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
    int file = open("ex1.txt", O_RDWR);
    struct stat st;
    stat("ex1.txt", &st);
    const char *string = "This is a nice day";
    char *memblock = mmap(NULL, st.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, file, 0);

    memcpy(memblock, string, strlen(string));
    ftruncate(file, strlen(string));
    msync(memblock, strlen(string), MS_SYNC);
    munmap(memblock, strlen(string));
    close(file);
    return 0;
}
