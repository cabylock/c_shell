#include<stdio.h>


void sort(int a[], int b[], int n)
{
   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         if(b[i] < b[j]) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        
         }
        
      }
   }
}

int main()
{
   int n;scanf("%d", &n);
   int a[n], b[n];
   for(int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
   }
   int slot[1000]= {0};
   int max_profit = 0;
   for(int i = 0; i < n; i++)
   {
      if(slot[a[i]] == 0)
      {
         slot[a[i]] = 1;
         max_profit += b[i];
      }
      else 
      {
         int j = a[i] - 1;
         while(j >= 0 && slot[j] == 1)
         {
            j--;
         }
         if(j > 0)
         {
            slot[j] = 1;
            max_profit += b[i];
         }
      }
   }
   printf("%d\n", max_profit);
   return 0;
}





