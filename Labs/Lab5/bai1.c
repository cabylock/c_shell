#include<stdio.h>
#include<pthread.h>

#define NUM_THREADS 2
#define MAX 10000000
long long odd_count = 0 ;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg)
{
   int *args = (int*)arg;
   int start = args[0];
   int end = args[1];
   
   for (int i = start; i < end; i++)
   {
      if (i % 2 != 0)
      {
         pthread_mutex_lock(&lock);
         odd_count++;
         pthread_mutex_unlock(&lock);
      }
   }
}

int main()
{
   pthread_t threads[NUM_THREADS];
   int length = MAX / NUM_THREADS;
   for (int i = 0; i < NUM_THREADS; i++)
   {
      int arg[2]; arg[0] = i * length;
      if(i == NUM_THREADS - 1)
         arg[1] = MAX;
      else
         arg[1] = (i + 1) * length;
      pthread_create(&threads[i], NULL, thread_function, (void*)arg);
   }
   for (int i = 0; i < NUM_THREADS; i++)
   {
      pthread_join(threads[i], NULL);
   }
   printf("Number of odd: %lld\n", odd_count);
   pthread_mutex_destroy(&lock);
}


