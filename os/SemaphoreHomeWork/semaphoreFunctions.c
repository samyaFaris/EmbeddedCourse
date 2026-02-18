#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define N 100
#define NUM_OF_THREADS 2

typedef unsigned int semaphore;

sem_t mutex;
sem_t empty;
sem_t full;
int counter = 0;

void insert_item()
{
    ++counter;
    printf("Insert Counter: %d \n", counter);
}
void remove_item()
{
    --counter;
    printf("Remove Counter: %d \n", counter);
}

void *producer(void *)
{
    for (int i = 0; i < 1000; i++)
    {
        // item = produce_item();
        sem_wait(&empty);
        sem_wait(&mutex);
        insert_item();
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *)
{
    for (int i = 0; i < 1000; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        remove_item();
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    int status;
    pthread_t threads[NUM_OF_THREADS];
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        if (i == 0)
        {
            status = pthread_create(&threads[i], NULL, producer, NULL);
            if (status < 0)
            {
                printf("Cant create the thread");
                exit(1);
            }
        }
        else
        {
            status = pthread_create(&threads[i], NULL, consumer, NULL);
            if (status < 0)
            {
                printf("Cant create the thread");
                exit(1);
            }
        }
    }
    for (int i = 0; i < NUM_OF_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}