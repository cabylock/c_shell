#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 2
int length;
int arr[10000];
int freq[255]= {0};
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
   int *args = (int *)arg;
   int start = args[0];
   int end = args[1];

   for (int i = start; i < end; i++)
   {
      pthread_mutex_lock(&lock);
      freq[arr[i]]++;
      
      pthread_mutex_unlock(&lock);
   }
}

int main()
{
   pthread_t threads[NUM_THREADS];
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   printf("Enter the elements of the array: ");
   int trunk = length / NUM_THREADS;
   for (int i = 0; i < length; i++)
   {
      scanf("%d", &arr[i]);
   }
   for (int i = 0; i < NUM_THREADS; i++)
   {
      int *arg = malloc(2 * sizeof(int));
      arg[0] = i * trunk;
      if (i == NUM_THREADS - 1)
         arg[1] = length;
      else
         arg[1] = (i + 1) * trunk;
      pthread_create(&threads[i], NULL, thread_function, (void *)arg);
   }
   for (int i = 0; i < NUM_THREADS; i++)
   {
      pthread_join(threads[i], NULL);
   }
   for(int i = 0; i < 255; i++)
   {
      if (freq[i] > 0)
      {
         printf("Element %d appears %d times\n", i, freq[i]);
      }
   }
   pthread_mutex_destroy(&lock);
}
