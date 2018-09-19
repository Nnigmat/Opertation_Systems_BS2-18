#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_func(void* thread_data)
{
    printf("Start thread number = %d\n", *(int*)thread_data);
    printf("End thread number = %d\n", *(int*)thread_data);
    free(thread_data);
    pthread_exit(0);
}


void main()
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    int n = 5;
    for (int i = 0; i < n;)
    {
        pthread_t thread;
        int *temp = malloc(sizeof(int));
        *temp = i;
        pthread_create(&thread, NULL, thread_func, temp);
        printf("Created thread number = %d\n", i);
        i+=1;
    }

}
