#include<stdio.h> 
#include<pthread.h> 

void * prints(void *arg)
{
	printf("thread message: %ld\n",pthread_self()); 
	
	pthread_exit(NULL);
}

int main(){
	pthread_t t1,t2,t3; 
	pthread_create(&t1,NULL,prints,NULL);
	pthread_create(&t2,NULL,prints,NULL);
	pthread_create(&t3,NULL,prints,NULL);
	pthread_join(t1,NULL); 
	pthread_join(t2,NULL); 
	pthread_join(t3,NULL); 
	printf("Main thread is running\n");
}







