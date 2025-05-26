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

int main ()
{
   int n; scanf("%d", &n);
   int a[n], b[n];
   for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
   }

   sort(a, b, n);
   int end = -1; 
   for (int i = 0; i < n; i++)
   {
      if(a[i] > end)
      {
         end = b[i];
         printf("%d %d\n", a[i], b[i]);
      }
   }
}




