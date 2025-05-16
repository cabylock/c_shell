#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   int fd[2];
   pipe(fd);

   pid_t pid = fork();
   if (pid == 0)
   {
      
      close(fd[0]);              
      dup2(fd[1], 1); 
      close(fd[1]);
      execlp("ls", "ls", (char *)NULL);
      perror("execlp ls");
   }
   else if (pid > 0)
   {
     
      close(fd[1]);             
      dup2(fd[0], 0); 
      close(fd[0]);
      execlp("wc", "wc", "-l", (char *)NULL);
      perror("execlp wc");
      wait(NULL);
   }
   else
   {
      perror("fork");
      return 1;
   }
   return 0;
}
