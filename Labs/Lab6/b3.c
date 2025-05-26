#include<stdio.h>

void sort(int a[], int b[], int n)
{
   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         if(a[i] > a[j]) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

           
         }
         if(b[i] > b[j]) {
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
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

   int max_room = 0;
   int j = 0; 
   sort(a, b, n);

   for (int i = 0; i < n; i++)
   {
      if (a[i] < b[j])
      {
         max_room ++;
      }
      else 
      {
         j++; 
      }
   }
   printf("%d\n", max_room);
}





