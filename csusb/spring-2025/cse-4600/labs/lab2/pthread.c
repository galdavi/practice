#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

//Thread Function, the reason the return type is void* is so functions can be passed to a pthread
void *Hello(void *thread_number)
{
    printf("Hello world from thread %ld!\n", (long)thread_number);

    //Send a message back from the thread.
    // allocating space for it
    // It's char* cast to void*
    char *message = (char *)malloc(50 * sizeof(char));
    strcpy(message, "I love steak and eggs.\n");
    pthread_exit((void *)message); //Called when a pthread is ready to exit.
}

int main()
{
    pthread_t thread_handle;            //When we create a thread we neeed a phandle.

    //Create one thread
    long thread_number = 1;
    pthread_create(&thread_handle, NULL, Hello, (void*)thread_number);
    
    //Have the main thread. say hello
    printf("Hello world form the main thread!\n");
    
    //Wait for child thread to join
    char *returned_message;
    pthread_join(thread_handle, (void **)&returned_message);
    printf("Message reads: %s\n",returned_message);

    //Deallocate memory, so we dont have a memory leak.

    free(returned_message);

    return 0;
}