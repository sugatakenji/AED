#include<stdio.h>
#include<stdlib.h>

void SetVet(long int n, long int* v);
long int Pares(long int n, long int* v);

int main()
{
   long int n, i;
   long int* v;
   scanf("%ld",&n);
   v = (long int*)malloc(n * sizeof(long int));
   SetVet(n, v);
   i = Pares(n, v);
   for(int i =  0; i < n; i +=2)
   {
       printf("%ld ", v[i]);
   }
   printf("%ld\n", i);
   free(v);
   
   return 0;
}

void SetVet(long int n, long int* v)
{
   for(int i = 0; i < n; i++)
   {
       scanf("%ld", &v[i]);
   }
}

long int Pares(long int n, long int* v)
{
   long int j = 0;
   for(long int i = 0; i < n; i++)
   {
       if(v[i] % 2 == 0)
       {
           j ++;
       }
   }
   return j;
}
