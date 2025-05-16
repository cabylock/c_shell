#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{

   
   int option;
   printf("Seclect an option 0 or 1 :\n");
   scanf("%d", &option);
   getchar();
   
  

   
      if (option == 0)
      {
         FILE *f = fopen("writefile.txt", "w");
         printf("enter content:\n");
         char buffer[1024];
         fgets(buffer, 1024, stdin);
         fputs(buffer, f);
         fclose(f);
      }
      else if (option == 1)
      {

         char filename[100];
         printf("enter file name: ");
         scanf("%s", filename);
         FILE *src = fopen(filename, "r");
         FILE *dst = fopen("writefile.txt", "w");
         char buffer[1024];
         int n = fread(buffer, 1, 1024, src);
         fwrite(buffer, 1, n, dst);
         fclose(src);
         fclose(dst);
      }
      else
      {
         printf("error input");
      }
   }


