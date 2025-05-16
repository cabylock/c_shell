#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRINGS 1000
#define MAX_STRING_LENGTH 100
#define NUM_THREADS 4
char strings[MAX_STRINGS][MAX_STRING_LENGTH];
char target[MAX_STRING_LENGTH];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int found_index = -1;
bool found_flag = false;

void *search_strings(void *arg)
{
   int *args = (int *)arg;

   for (int i = args[0]; i < args[1]; i++)
   {

      pthread_mutex_lock(&lock);
      bool already_found = found_flag;
      pthread_mutex_unlock(&lock);

      if (already_found)
      {
         found_index = -1;
         break;
      }

      if (strcmp(strings[i], target) == 0)
      {
         pthread_mutex_lock(&lock);
         // Set the found flag to true
         found_flag = true;
         found_index = i;
         pthread_mutex_unlock(&lock);
         break;
      }
   }

   return NULL;
}

int main()
{
   printf("Enter the number of strings: ");
   int num_strings;
   scanf("%d", &num_strings);

   printf("Enter the strings:\n");
   for (int i = 0; i < num_strings; i++)
   {
      scanf("%s", strings[i]);
   }

   getchar();
   printf("Enter the target string to search for: ");
   scanf("%s", target);


   pthread_t threads[NUM_THREADS];

   int chunk_size = (num_strings + NUM_THREADS - 1) / NUM_THREADS;

   for (int i = 0; i < NUM_THREADS; i++)
   {
      int *args = malloc(2 * sizeof(int));
      args[0] = i * chunk_size;
      args[1] = (i + 1) * chunk_size < num_strings ? (i + 1) * chunk_size : num_strings;

      pthread_create(&threads[i], NULL, search_strings, args);
   }

   for (int i = 0; i < NUM_THREADS; i++)
   {
      pthread_join(threads[i], NULL);
   }

   if (found_flag)
   {
      printf("Target string \"%s\" found at index %d\n", target, found_index);
   }
   else
   {
      printf("Target string \"%s\" not found\n", target);
   }

   pthread_mutex_destroy(&lock);

   return 0;
}
