#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define THRESHOLD 10

int arr[MAX_SIZE];
int n;

void sequential_quicksort(int left, int right)
{
   if (left >= right)
      return;

   int pivot = arr[right];
   int i = left - 1;

   for (int j = left; j < right; j++)
   {
      if (arr[j] <= pivot)
      {
         i++;
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   i++;
   int temp = arr[i];
   arr[i] = arr[right];
   arr[right] = temp;

   sequential_quicksort(left, i - 1);
   sequential_quicksort(i + 1, right);
}

void *parallel_quicksort(void *arg)
{
   int *range = (int *)arg;
   int left = range[0];
   int right = range[1];
   free(arg);

   if (left >= right)
      return NULL;

   if (right - left + 1 <= THRESHOLD)
   {
      sequential_quicksort(left, right);
      return NULL;
   }

   int pivot = arr[right];
   int i = left - 1;

   for (int j = left; j < right; j++)
   {
      if (arr[j] <= pivot)
      {
         i++;
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }
   }
   i++;
   int temp = arr[i];
   arr[i] = arr[right];
   arr[right] = temp;

   pthread_t left_thread, right_thread;

   int *left_range = malloc(2 * sizeof(int));
   left_range[0] = left;
   left_range[1] = i - 1;

   int *right_range = malloc(2 * sizeof(int));
   right_range[0] = i + 1;
   right_range[1] = right;

   pthread_create(&left_thread, NULL, parallel_quicksort, left_range);
   pthread_create(&right_thread, NULL, parallel_quicksort, right_range);

   pthread_join(left_thread, NULL);
   pthread_join(right_thread, NULL);

   return NULL;
}

int main()
{
   printf("Enter number of elements (max %d): ", MAX_SIZE);
   scanf("%d", &n);

   printf("Enter %d integers:\n", n);
   for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);

   int *initial_range = malloc(2 * sizeof(int));
   initial_range[0] = 0;
   initial_range[1] = n - 1;

   pthread_t main_thread;
   pthread_create(&main_thread, NULL, parallel_quicksort, initial_range);
   pthread_join(main_thread, NULL);

   printf("Sorted array:\n");
   for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   return 0;
}
