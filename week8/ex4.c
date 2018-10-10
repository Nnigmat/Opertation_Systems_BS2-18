#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
    int mb = 10*1024*1024*8;
    for (int i = 0; i < 10; i++)
    {
        memset(malloc(mb), 0, mb);
        struct rusage us;
        getrusage(RUSAGE_SELF, &us);
        printf("%lu\n", us.ru_maxrss);
        sleep(1);
    }

    return 0;
}
