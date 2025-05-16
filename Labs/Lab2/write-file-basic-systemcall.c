#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>


int main(){

	
	int option ; 
	printf("Seclect an option 0 or 1 :\n");
	scanf("%d",&option);	getchar();
	

		if(option  == 0)
		{
		int fd = open("writefile.txt", O_CREAT| O_WRONLY, 0644); 
		char buffer[1024]; 
		printf("enter the content of file\n"); 
		ssize_t n = read(0, buffer,1024); 
		write(fd,buffer,n);
		close(fd); 
		 
		}
		else if ( option == 1)
		{
		char filename[100]; 
		printf("enter file name: ");
		scanf("%s",filename);
		char buffer[1024];  
		int fd1 = open(filename, O_RDONLY); 
		ssize_t n = read(fd1 , buffer, 1024); 
		int fd2 = open("writefile.txt", O_CREAT| O_WRONLY, 0644 ); 
		write(fd2,buffer,n); 
			
		close(fd1); close(fd2);
		}
		else 
		{
		printf("error input");
		}
	
	
}



