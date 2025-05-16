#include<pthread.h> 
#include<stdio.h>
#include<stdlib.h>

void *sum(void*arg){
	int n = *((int*) arg); 
	int* res =  malloc(sizeof(int));
	*res = 0;
	for(int i = 1; i<= n ; i++){
		*res += i ; 	
	}
	return res; 
}

int main(){
	pthread_t t1; int n ; scanf("%d",&n);
	void *res;
	pthread_create(&t1, NULL, sum, &n);
	pthread_join(t1, &res); 
	printf("sum : %d\n",*(int*)res); 

}



