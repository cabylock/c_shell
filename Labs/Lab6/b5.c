#include<stdio.h>


void sort(int w[], int v[], int n)
{
   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         if((double)v[i] / w[i] < (double)v[j] / w[j]) {
            int temp_w = w[i];
            w[i] = w[j];
            w[j] = temp_w;
            int temp_v = v[i];
            v[i] = v[j];
            v[j] = temp_v;
         }
      }
   }
}



int main()
{
   int mW; scanf("%d", &mW);
   int n; scanf("%d", &n);
   int w[n], v[n];
   for(int i = 0; i < n; i++) {
      scanf("%d", &w[i]);
      scanf("%d", &v[i]);
   }

   int max_value = 0;
   sort(w, v, n);
   for (int i = 0; i < n; i++)
   {
      if (mW >= w[i])
      {
         mW -= w[i];
         max_value += v[i];
      }
      else 
      {
         max_value += (double)v[i] / w[i] * mW;
         break;
      }
   }
   printf("%d\n", max_value);





}



