#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count = 0;

void *thread_function(void *arg)
{

   pthread_mutex_lock(&mutex);

   printf("Thread %d reached the barrier\n", *(int *)arg);
   count++;

   if (count == 4)
   {
      printf("All threads reached the barrier! Releasing them...\n");
      pthread_cond_broadcast(&cond); // Wake up all waiting threads
   }
   else
   {
      while (count < 4)
      {
         pthread_cond_wait(&cond, &mutex); // Wait until the last thread arrives
      }
   }
   pthread_mutex_unlock(&mutex);
   printf("Thread %d passed the barrier\n", *(int *)arg);
   return NULL;
}

int main()
{
   pthread_t threads[4];
   for (int i = 0; i < 4; ++i)
   {
      int *arg = malloc(sizeof(*arg));
      *arg = i;
      pthread_create(&threads[i], NULL, thread_function, arg);
   }

   for (int i = 0; i < 4; ++i)
   {
      pthread_join(threads[i], NULL);
   }

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cond);

   return 0;
}
