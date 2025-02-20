#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10          //Buffer size.

int buffer[BUFFER_SIZE];
int count = 0;                  //Number of iootems in the buffer.
pthread_mutex_t mutex;          //Mutex
pthread_cond_t not_full;        //Condition variable for a not-full buffer
pthread_cond_t not_empty;       //Condition variable for a not-empty buffer

int PRODUCE_TIME = 2;           //How long it takes to produce an item.
int CONSUME_TIME = 1;           //How long it takes to consume an item.

int NUM_ITEMS = 10;             //How many items to produce/consume

void* Producer()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        //Produce an item
        int item = i +1;
        
        //Acuire the lock
        pthread_mutex_lock(&mutex);

        //If the buffer is full, wait for it to empty.
        while (count == BUFFER_SIZE)
        {
            printf("Buffer is full. Producer is waiting for buffer to emptyy...\n");
            pthread_cond_wait(&not_full, &mutex);
        }

        buffer[count++] = item;
        printf("Producer has added an item to the buffer: %d\n", item);

        //If the buffer was empty, signal to the consumer that there's an itme to be taken out.
        pthread_cond_signal(&not_empty);

        //Releas Lock
        pthread_mutex_unlock(&mutex);
        
        //Sleep
        sleep(PRODUCE_TIME);
    }
    
    printf("Producer has finished producing.\n");
    return NULL;
}

//Consumer thread
void* Consumer()
{
    //Consume items from the buffer
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        //Aqcuire the lock
        pthread_mutex_lock(&mutex);

        //If the bufffer is empty, wait for it fill up.
        while (count == 0)
        {
            printf("Buffer is empty. Consumer is waiting for buffer to fill...\n");
            pthread_cond_wait(&not_empty, &mutex);
        }

        int item = buffer[--count];
        printf("Consumer has taken an item from the buffer: %d\n", item);

        //If the bufffer was full, signal to the producer that there's space for new items
        pthread_cond_signal(&not_full);
        
       pthread_mutex_unlock(&mutex);

       sleep(CONSUME_TIME);

    }
    

    printf("Consumer has finished consuming.\n");
    return NULL;
}

//Main Function
int main()
{
    //Thread handles
    pthread_t producer_thread, consumer_thread;

    //Intialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);
    
    //Create producer and consumer threads.
    pthread_create(&producer_thread, NULL, Producer,NULL);
    pthread_create(&consumer_thread, NULL, Consumer,NULL);

    //Join threads. 
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    //Cleanup 
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);
    return 0;
}