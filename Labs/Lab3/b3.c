#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
   pid_t pid = fork();

   if (pid == 0)
   {
      // Child process: execute 'ls' on user's home directory
      char *home = getenv("HOME");
      execlp("ls", "ls", home, (char *)NULL);
      // If execlp fails
      perror("execlp");
      return 1;
   }
   else if (pid > 0)
   {
      // Parent process: wait for child
      wait(NULL);
   }
   else
   {
      perror("fork");
      return 1;
   }
   return 0;
}
