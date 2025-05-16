#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>

int main(){

	int fd = open("Hello.txt", O_RDWR);
	
	off_t newpos = lseek(fd,7, SEEK_SET);
	char buffer [1024];
	ssize_t  r = read (fd,buffer , 1024);
	printf("%s",buffer);
	
	
	close(fd);

}



