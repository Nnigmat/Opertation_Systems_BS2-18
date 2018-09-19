#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int size_of_elements = 0, capacity = 20;
int adder, remover;

void* add_to_buffer(void* data)
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    while (1)
    {
        if (adder)
        {
            for (int i = 0; i < capacity; i++)
            {
                size_of_elements++;
                printf("%d\n", size_of_elements);
            }
            adder = 0;
            remover = 1;
        }
        else
        {
            sleep(1);
        }
    }
}

void* remove_from_buffer(void* data)
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    while (1)
    {
        if (remover)
        {
            for (int i = size_of_elements; i > 0; i--)
            {
                size_of_elements--;
                puts("%d\n", size_of_elements);
            }
            remover = 0;
            adder = 1;
        }
        else
        {
            sleep(1);
        }
    }
}

void main()
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    adder = 1;
    remover = 0;
    pthread_t thread_id1, thread_id2;
    pthread_create(&thread_id1, NULL, add_to_buffer, NULL);
    printf("Created first thread\n");
    pthread_create(&thread_id2, NULL, remove_from_buffer, NULL);
    printf("Created second thread\n");
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
}
