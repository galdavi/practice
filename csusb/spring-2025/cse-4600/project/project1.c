#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void FCFS(int *burst_times, int num_processes);
void SJF(int *burst_times, int num_processes);
void RR(int *burst_times, int num_processes, int quantum);

// Helper function prototypes
void printProcess(int *bust_times, int *process_ids, int num_processes);
void bubbleSort(int *bust_times, int *process_ids, int num_processes);

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

    // FCFS(burst_times, num_processes);
    // SJF(burst_times, num_processes);
    RR(burst_times, num_processes, 2);

    // Since we are allocating memory we need to deallocte memory.
    // Avoids memory leak.
    free(burst_times);
    return 0;
}

// Helper function used to print all the process in order(Array order)
void printProcess(int *bust_times, int *process_ids, int num_process)
{
    for (int i = 0; i < num_process; ++i)
    {
        printf("Process %i: \tBT: %i \n", process_ids[i], bust_times[i]);
    }
}

// Helping sorting function that uses bubble sort to sort the processes from least to greatest
void bubbleSort(int *burst_times, int *process_ids, int num_processes)
{
    for (int i = 0; i < num_processes - 1; ++i)
    {
        int endOfArrayIndex = num_processes - i;
        bool swapped = false;

        for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            int temp = 0;
            if (burst_times[currentIndex] > burst_times[currentIndex + 1])
            {
                temp = burst_times[currentIndex];
                burst_times[currentIndex] = burst_times[currentIndex + 1];
                burst_times[currentIndex + 1] = temp;

                temp = process_ids[currentIndex];
                process_ids[currentIndex] = process_ids[currentIndex + 1];
                process_ids[currentIndex + 1] = temp;
            }
        }
    }
}
void FCFS(int *burst_times, int num_processes)
{
    // Declare variables
    int time_elapsed = 0;
    float avg_waiting_time = 0.0f;
    float avg_turnaround_time = 0.0f;

    // Calculate each process's waiting time and turnaround times using a for loop
    for (int i = 0; i < num_processes; ++i)
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

    printf("Avg TAT: %f \tAvg WT: %f", avg_turnaround_time, avg_waiting_time);

    return;
}

void SJF(int *burst_times, int num_processes)
{

    // Declare the arrays we will be using so that we can copy and sort the original array
    int *sorted_burst_times = (int *)malloc(num_processes * sizeof(int));
    int *process_ids = (int *)malloc(num_processes * sizeof(int));

    // Declares variables
    int time_elapsed = 0;
    float avg_waiting_time = 0.0f;
    float avg_turnaround_time = 0.0f;

    // Copy original array and process IDs.
    for (int i = 0; i < num_processes; ++i)
    {
        sorted_burst_times[i] = burst_times[i]; // Copy the burst times from our original array into our new array, that will be sorted.
        process_ids[i] = i;                     // Populate the process IDs into our array
    }

    // Using bubble sort, sort the processes from shortest job to largest job.
    bubbleSort(sorted_burst_times, process_ids, num_processes);

    // Calculate each process' waiting time and turnaround times using a for loop
    for (int i = 0; i < num_processes; ++i)
    {
        int burst_time = sorted_burst_times[i];
        time_elapsed += burst_time;

        int turnaround_time = time_elapsed;

        int wait_time = turnaround_time - burst_time;

        printf("Process %i \tBT:%i \tWT:%i \tTAT: %i \n", process_ids[i], burst_time, wait_time, turnaround_time);

        avg_waiting_time += wait_time;
        avg_turnaround_time += turnaround_time;
    }

    // Deallocate memory
    free(sorted_burst_times);
    free(process_ids);

    avg_waiting_time /= (float)num_processes;
    avg_turnaround_time /= (float)num_processes;

    printf("Avg TAT: %f \tAvg WT: %f", avg_turnaround_time, avg_waiting_time);

    return;
}

void RR(int *burst_times, int num_processes, int quantum)
{

    // Declare variables and pointers
    int *time_remaining = (int *)malloc(num_processes * sizeof(int));
    int time_elapsed = 0;
    bool all_processes_complete = false;
    float avg_waiting_time = 0.0f;
    float avg_turnaround_time = 0.0f;

    // Copy the the burst times into time_remaining array.
    for (int i = 0; i < num_processes; ++i)
    {
        time_remaining[i] = burst_times[i];
    }

    // Run this line of code into we complete the processes
    while (!(all_processes_complete))
    {
        for (int i = 0; i < num_processes; ++i)
        {
            
            if(time_remaining[i] == 0)
                continue;

            int current_quantum = quantum;
            
            if(time_remaining[i] < quantum)
                current_quantum = time_remaining[i];

            time_elapsed+= current_quantum;
            time_remaining[i] -= current_quantum;

            if(time_remaining[i] == 0)
            {
                int turnaround_time = time_elapsed;

                int wait_time = turnaround_time - burst_times[i];
        
                printf("Process %i \tBT:%i \tWT:%i \tTAT: %i \n", i, burst_times[i], wait_time, turnaround_time);
        
                avg_waiting_time += wait_time;
                avg_turnaround_time += turnaround_time;
            }
        }

        all_processes_complete = true;
        for(int j = 0; j < num_processes; j++){
            all_processes_complete = all_processes_complete && (time_remaining[j] == 0);
        }
    }
    // Deallocate Memory
    free(time_remaining);
    return;
}