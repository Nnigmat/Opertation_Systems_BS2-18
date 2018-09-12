#include <sys/types.h>
#include <unistd.h>

void main()
{
    for (int i = 0; i < 5; i++)
    {
        fork();
    }
    sleep(5);
}
