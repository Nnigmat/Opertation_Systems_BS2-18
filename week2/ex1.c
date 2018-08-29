#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() 
{
    int integer;
    float fl;
    double doub;

    integer = INT_MAX;
    fl = FLT_MAX;
    doub = DBL_MAX;

    printf("Integer size - %d, value - %d\n", sizeof(integer), integer);
    printf("Float size - %d, value - %f\n", sizeof(fl), fl);
    printf("Double size - %d, value - %f\n", sizeof(doub), doub);

    return 0;
}
