#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
long nelems_p_t, gsum = 0; /* Global sum */
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
void *psum(void *arg)
{
   long i, myid = *((long *)arg);
   long start = myid * nelems_p_t + 1;
   long end = start + nelems_p_t;
   for (i = start; i < end; i++)
   {
      pthread_mutex_lock(&mtx);
      gsum += i;
      pthread_mutex_unlock(&mtx);
   }
}
void main(int argc, char *argv[])
{
   long i, nelems = 1 << 8, myid[4];
   pthread_t tid[4];
   char *endptr;
   long nthreads = strtol(argv[1], &endptr, 10);
   nelems_p_t = nelems / nthreads;
   /* Create peer threads and wait for them to finish */
   for (i = 0; i < nthreads; i++)
   {
      myid[i] = i;
      pthread_create(&tid[i], NULL, psum, &myid[i]);
   }
   for (i = 0; i < nthreads; i++)
      pthread_join(tid[i], NULL);
   printf("Total sum = %ld\n", gsum);
}
