#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
   int fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
   if (fd == -1) {
       perror("Error opening file");
       return 1;
   }
   write(fd, argv[1], sizeof(argv[1]));
   close(fd);
}


