#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void FCFS(int *burst_times, int num_processes);
void SJF(int *burst_times, int num_processes);
void RR(int *burst_times, int num_processes, int quantums);

int main()
{

    // Declare variables
    int num_processes;
    int *burst_times;

    // Ask the user for how many process to run.
    printf("Enter the number of process you will run: ");
    scanf("%d", &num_processes);

    burst_times = (int *)malloc(num_processes * sizeof(int));

    // Ask the user how long are the processes running for.
    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter the burst time for process %i of %i: ", i, num_processes);
        scanf("%d", &burst_times[i]);
    }

    // Print out the process burst time
    printf("The following process will arrive at time 0 with these burst times:");
    for (int i = 0; i < num_processes; i++)
    {
        printf(" %i", burst_times[i]);
    }

    printf("\n");

    // Calls the scheduling algorithm

    FCFS(burst_times, num_processes);
    // SJF(burst_times, num_processes);
    // RR(burst_times, num_processes, 3);

    // Since we are allocating memory we need to deallocte memory.
    // Avoids memory leak.
    free(burst_times);
    return 0;
}

void FCFS(int *burst_times, int num_processes)
{
    // Declare variables
    int time_elapsed = 0;
    float avg_waiting_time = 0.0f;
    float avg_turnaround_time = 0.0f;

    // Calculate each proces's waiting end and turnaround times in a for loop
    for (int i = 0; i < num_processes; i++)
    {
        int burst_time = burst_times[i];
        
        time_elapsed += burst_time;

        int turnaround_time = time_elapsed;

        int wait_time = turnaround_time - burst_time;

        printf("Process %i \tBT:%i \tWT:%i \tTAT: %i \n", i, burst_time, wait_time, turnaround_time);

        avg_waiting_time += wait_time;
        avg_turnaround_time += turnaround_time;
    }

    avg_waiting_time /= (float)num_processes;
    avg_turnaround_time /= (float)num_processes;

    printf("Avg TAT: %f \tAvg WT: %f",avg_turnaround_time ,avg_waiting_time);

    return;
}

void SJF(int *burst_times, int num_processes){

    //Declare the arrays we will be using so that we can copy and sort the original array
    int* sorted_burst_times = (int*)mallow(num_processes *sizeof(int));
    int* process_ids = (int*) malloc(num_processes *sizeof(int));

    //Declares variables
    int time_elapsed = 0;
    float avg_waiting_time = 0.0f;
    float avg_turnaround_time = 0.0f;

    //Copy original array and process IDs.
    for(int i = 0; i < num_processes; i++){
        sorted_burst_times[i] = burst_times[i];     //Copy the burst times from our original array into our new array, that will be sorted.
        process_ids[i]= i;                          //Populate the process IDs into our array
    }

    //Sort burst times.
    for(int i = 0;  i < num_processes; i++){
        
    }
    //Deallocate memory
    free(sorted_burst_times);
    free(process_ids);

    avg_waiting_time /= (float)num_processes;
    avg_turnaround_time /= (float)num_processes;

    printf("Avg TAT: %f \tAvg WT: %f",avg_turnaround_time ,avg_waiting_time);

    return;
}