#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int counter = 200;  
void *p1(void *arg)
{
   pthread_mutex_lock(&mtx);
   for(int i=0; i<100; i++)
   {
      counter++;
   }
   pthread_mutex_unlock(&mtx);
}

void * p2(void *arg)
{
   pthread_mutex_lock(&mtx);
   for(int i=0; i<50; i++)
   {
      counter--;
   }
   pthread_mutex_unlock(&mtx);
}
int main()
{
   pthread_t t1, t2;
   pthread_create(&t1, NULL, p1, NULL);
   pthread_create(&t2, NULL, p2, NULL);
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   printf("Final value of counter: %d\n", counter);
   return 0;
}





