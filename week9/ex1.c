#include <stdio.h>

double aging_algorithm(FILE *file, int page_frames)
{
    int hit = 0, miss = 0, mem;
    struct Frame {
        int mem, count;
    } pages[page_frames];

    // Fill counters array with zeroes 
    for (int i = 0; i < page_frames; i++)
    {
        pages[i].mem = 0;
        pages[i].count = 0;
    }

    while (fscanf(file, "%d", &mem) != EOF)
    {
        int found = -1, least_index, min = 256;
        for (int i = 0; i < page_frames; i++)
        {
            if (pages[i].mem == mem)
            {
                hit++;
                found = i;
            }
            else if (pages[i].count < min || pages[i].mem == 0)
            {
                min = pages[i].count; 
                least_index = i;
            }

           pages[i].count = pages[i].count >> 1;
        }

        if (found != -1)
        {
            // 127 == 2 ^ 8 - 1. We add 8th bit
            pages[found].count += 127;
        }
        else 
        {
            miss++;
            pages[least_index].mem = mem;
            pages[least_index].count = 127;
        }
    }

    printf("hit %d\n miss %d\n", hit, miss);
    return (double) hit / miss;
}

int main()
{
    int page_frames[4] = {10, 50, 100, 1000};
    
    for (int i = 0; i < 4; i++)
    {
        FILE *file = fopen("input.txt", "r");
        printf("%d Page frames Hit/Miss ratio: %f\n", 
                page_frames[i], aging_algorithm(file, page_frames[i]));
        fclose(file);
    }
    return 0;
}
