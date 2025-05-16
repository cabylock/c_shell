#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int N; // matrix size NxN
int A[MAX_SIZE][MAX_SIZE];
int B[MAX_SIZE][MAX_SIZE];
int C[MAX_SIZE][MAX_SIZE];



void *multiply_row(void *arg)
{
   int row = *(int *)arg;
   free(arg);

   for (int j = 0; j < N; j++)
   {
      int sum = 0;
      for (int k = 0; k < N; k++)
      {
         sum += A[row][k] * B[k][j];
      }
      C[row][j] = sum;
   }


   return NULL;
}

int main()
{
   printf("Enter the size N of NxN matrices (max %d): ", MAX_SIZE);
   scanf("%d", &N);
  
   printf("Enter matrix A (%d x %d):\n", N, N);
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         scanf("%d", &A[i][j]);

   printf("Enter matrix B (%d x %d):\n", N, N);
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         scanf("%d", &B[i][j]);

   pthread_t threads[N];

   for (int i = 0; i < N; i++)
   {
      int *row = malloc(sizeof(int));
      *row = i;
      pthread_create(&threads[i], NULL, multiply_row, row);
   }

   for (int i = 0; i < N; i++)
      pthread_join(threads[i], NULL);



   printf("Result matrix C = A * B:\n");
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
         printf("%d ", C[i][j]);
      printf("\n");
   }

   return 0;
}
