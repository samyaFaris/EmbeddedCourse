#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX 1000
sem_t semOdd;
sem_t semEven;
void* printOdd(void* arg)
{
    for (int i = 1; i <= MAX; i += 2)
    {
        sem_wait(&semOdd);
        printf("%d\n", i);
        sem_post(&semEven);
    }
}
void* printEven(void* arg)
{
    for (int i = 2; i <= MAX; i += 2)
    {
        sem_wait(&semEven);
        printf("%d\n", i);
        sem_post(&semOdd);
    }
}
int main()
{
    pthread_t t1, t2;
    sem_init(&semOdd,0,1);
    sem_init(&semEven,0,0);
    pthread_create(&t1,NULL,printOdd,NULL);
    pthread_create(&t2,NULL,printEven,NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&semOdd);
    sem_destroy(&semEven);
    return 0;
}