#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

#define CMDSIZ 32
void process_command(char * cmdbuf)
{
   int pid, status;
   char * argv[CMDSIZ];
   char * token = strtok(cmdbuf, " ");
   int i = 0;
   while(token != NULL){
      argv[i++] = token;
      token = strtok(NULL, " ");
   }
   argv[i] = NULL;
   if((pid = fork()) == 0){
      execvp(argv[0], argv);

      _exit(1);
   }
   else  waitpid(pid, &status, 0);
}
int main(int argc, char * argv[])
{
   int logout = 0, cmdsiz; char cmdbuf[CMDSIZ];
   while(!logout){
      write(1,"myshell> ", 8);
      cmdsiz = read(0, cmdbuf, CMDSIZ);
      cmdbuf[cmdsiz-1] = '\0'; 
      if(strcmp("logout", cmdbuf) == 0)
      {
        ++logout;
      }
      else
         process_command(cmdbuf);
   }
}


