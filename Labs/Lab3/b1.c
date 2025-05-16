#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

extern int idata; 

int main()
{
    printf("%d ", idata);
    __pid_t p1 = fork();

    if (p1 == 0)
    {
        // child process
        printf("child\n");
        return 0;
    }
    else
    {
        // parent process
        printf("parent\n");
        int status;
        __pid_t child_pid = wait(&status);
        printf("child pid: %d  %d exit with %d \n", child_pid,p1, status);
    }
   
}
