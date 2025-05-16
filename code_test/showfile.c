#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[]){
	FILE  *fptr ;
	fptr = fopen(argv[1],"r"); 
	
	char c ; 
	while(( c = fgetc(fptr)) != EOF)
	{
		printf("%c",c);
	}



}
