#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int mb = 10*1024*1024*8;
    for (int i = 0; i < 10; i++)
    {
        memset(malloc(mb), 0, mb);
        sleep(1);
    }

    return 0;
}
