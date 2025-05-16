#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void handle_sigint(int sig){
   printf("\nProgram is terminated by user\n");  exit(0);
}
void list_files(const char *folder){
   DIR *dir = opendir(folder);
   struct dirent *entry;
   struct stat st;
   char path[1024];
   printf("Files in %s:\n", folder);
   while ((entry = readdir(dir)) != NULL){
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
         continue;
      snprintf(path, sizeof(path), "%s/%s", folder, entry->d_name);
      if (stat(path, &st) == 0 && S_ISREG(st.st_mode)){
         printf("  %s  ", entry->d_name);
      }
   }
   printf("\n");   closedir(dir);
}
int main(int argc, char *argv[]){
   signal(SIGINT, handle_sigint);
   while (1){
      list_files(argv[1]);
      sleep(60); 
   }
   return 0;
}
