#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    //create a new process and save its PID
    pid_t pid;
    pid = fork();
    int status;

    if(pid < 0)
    {
        //an error has occured while trying to for
        perror("fork error.\n");
        return 1;
    } else if(pid ==0)
    {
        //this is the child process
        printf("Arcane (PID%d)\n", getpid());

        // Sleep for 5s to simulate a process "working"
        sleep(1);

        printf("Child process has completed its work.\n");

    } else 
    {
        //Parent Process
        printf("David Solis Gallo (PID%d)\n", getpid());
        
        //Sleep for 2s to simualte a process "working"
        sleep(3);
        printf("Parent process has completed its work.\n");
        
        //wait for child to finish running
        waitpid(pid,&status, 0);

        //print that the child has exited
        printf("Child process has exited with status %d.\n", WEXITSTATUS(status));
    }

    return 0;
}