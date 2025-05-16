#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>


int check(const char* name , const char *word)
{
	FILE *file = fopen(name, "r"); 
	if( file == NULL){perror("can't open"); return 0; }
	
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, word) != NULL) {
            	fclose(file);
		return 1; 
        }
    }    
    fclose(file);
    return 0;

}
int main(int argc , char *argv[])
{

	DIR *dir = opendir(argv[2]); 
	struct dirent *entry; 
	while( (entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
       		 }	
	char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", argv[2], entry->d_name);
        
        if (entry->d_type == DT_REG) {
            if (check(filepath, argv[1])) {
                printf("%s\n", entry->d_name);
            }
        }	
	}
	closedir(dir);
       return 0;

}



