#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

static int idata = 1000; 

int main(){

   int istack = 150;
   int status = 0;
   int fd = open("Hello.txt", O_RDWR);
   pid_t childPid = fork();

   if(childPid == 0)
   {
      printf("%d %d \n",istack, idata);
      istack =200; idata =500; 
      printf("%p %p \n",&istack, &idata);
      lseek(fd, 7, SEEK_SET);

   }
   else {
      waitpid(childPid, &status, 0); 
      printf("%d %d \n",istack, idata);
      char buffer[15] ; 
      read(fd,buffer,sizeof(buffer));
      printf("%s\n ", buffer);
      close(fd);
   }
}
