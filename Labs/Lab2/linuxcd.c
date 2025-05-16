#include<stdio.h> 
#include<unistd.h>

int main( int argc, char * argv[])
{

	if(chdir(argv[1]) == 0)
	{	
		char buffer[1024];
		getcwd(buffer , sizeof(buffer)); 
		printf("%s \n", buffer);
	}
	else 
	{
		perror("error");
	}
	
}


