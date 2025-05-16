#include<fcntl.h>
#include<unistd.h>
#include<stdio.h> 
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	struct stat sb; 
	if (stat(argv[1], &sb) == -1) {
	perror("stat");
	exit(-1);
	}
	printf("File size: %lld bytes\n", (long long) sb.st_size);
	printf("access mode: %o\n",sb.st_mode);
	




}





