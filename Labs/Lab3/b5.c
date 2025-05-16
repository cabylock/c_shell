#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
  int pipe1[2]; 
  int pipe2[2]; 
  pipe(pipe1);
  pipe(pipe2);

  __pid_t pid = fork();
  if (pid == 0)
  {
    // Child process
    close(pipe1[0]);
    close(pipe2[1]); 
    write(pipe1[1], "Hello parent", 13);
    close(pipe1[1]);
    char buf[32] = {0};
    read(pipe2[0], buf, sizeof(buf));
    printf("from parent: %s\n", buf);
    close(pipe2[0]);
  }
  else
  {
    // Parent process
    close(pipe1[1]); 
    close(pipe2[0]); 
    char buf[32] = {0};
    read(pipe1[0], buf, sizeof(buf));
    printf("from child: %s\n", buf);
    close(pipe1[0]);
    write(pipe2[1], "Hello children", 15);
    close(pipe2[1]);
  
  }
}
