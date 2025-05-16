#include<pthread.h>
#include<stdio.h> 


void *prints(void *arg)
{  
   int n = *((int*) arg);
   for(int i = 1; i<= n ; i++){
      printf("%d\n",i); 
   }

}

int main()
{
   pthread_t thread1 ;
   int n; scanf("%d", &n);
   pthread_create(&thread1, NULL, prints, &n);
   pthread_join(thread1, NULL);
   printf("Main thread exiting\n");
   return 0;

}
