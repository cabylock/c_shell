#include<stdio.h>


void sort(int a[], int b[], int n)
{
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         if (b[i] > b[j]) {
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
         }
      }
   }
}


int main()
{
   int n; scanf("%d", &n);
   int a[n], b[n]; 
   for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
   }
   int latency = 0;
   int time_processed = 0;
   sort(a, b, n);
   for (int i = 0; i < n; i++)
   {
      printf("%d ", b[i] );
      time_processed += a[i];
      if(time_processed > b[i])
      {
         latency += time_processed - b[i];
      }
   }

   printf("Latency: %d\n", latency);
   return 0;
}
