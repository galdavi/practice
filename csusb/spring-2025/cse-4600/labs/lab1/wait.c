#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    // creates a new process and save its PID
    pid_t pid1, pid2;
    pid1 = fork();
    int status1, status2;

    if (pid1 < 0)
    {
        // An error has occured while trying to fork
        perror("Fork error.\n");
        return 1;
    }
    else if (pid1 == 0)
    {
        // This is the firs child process, which prints my major.
        printf("Computer Science (PID %d)\n", getpid());
    }
    else
    {
        // this is the parent process, which prints my name
        printf("David Solis Gallo (PID %d)\n", getpid());

        // have the parent call fork again
        pid2 = fork();

        if (pid2 < 0)
        {
            // An error has occred while trying to fork again
            perror("Fork error.\n");
            return 1;
        }
        else if (pid2 == 0)
        {
            // This is the second child process, which prints the year I am expected to graduate.
            printf("Spring 2026 (PID %d)\n", getpid());
        }
        else
        {
            // This is the parent after forking a second time
            // wait for the children to finish running
            waitpid(pid1, &status1, 0);
            printf("Child process 1 has exited with status %d\n", WEXITSTATUS(status1));

            waitpid(pid2, &status2, 0);
            printf("Child process 2 has exited with status %d\n", WEXITSTATUS(status2));
        }
    }

    return 0;
}