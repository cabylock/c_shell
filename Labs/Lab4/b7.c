#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t cv_full, cv_empty;

void *producer(void *arg)
{
   while (1)
   {
      pthread_mutex_lock(&mutex);
      for (int i = 0; i < 10; i++)
      {
         buffer[i] = i;
         count++;
         printf("Produced: %d\n", i); sleep(1);
      }

      pthread_cond_signal(&cv_empty);
      while (count > 0)
      {
         pthread_cond_wait(&cv_full, &mutex);
      }
      pthread_mutex_unlock(&mutex);
   }
   
}

void *consumer(void *arg)
{
   while (1)
   {
      pthread_mutex_lock(&mutex);
      while (count == 0)
      {
         pthread_cond_wait(&cv_empty, &mutex);
      }
      for (int i = 9; i >= 0; i--)
      {
         printf("Consumed: %d\n", buffer[i]); sleep(1);
      }
      count = 0; 
      pthread_cond_signal(&cv_full);
      pthread_mutex_unlock(&mutex);
      
   }
   
}

int main()
{
   pthread_t prod_thread, cons_thread;

   pthread_mutex_init(&mutex, NULL);
   pthread_cond_init(&cv_full, NULL);
   pthread_cond_init(&cv_empty, NULL);

   pthread_create(&prod_thread, NULL, producer, NULL);
   pthread_create(&cons_thread, NULL, consumer, NULL);

   pthread_join(prod_thread, NULL);
   pthread_join(cons_thread, NULL);

   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&cv_full);
   pthread_cond_destroy(&cv_empty);
   return 0;
}
