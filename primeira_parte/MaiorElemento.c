#include<stdio.h>
#include<stdlib.h>

void SetVet(long int n, long int* v);
long int MaiorElem(long int n, long int* v);

int main()
{
   long int n, i;
   long int* v;
   scanf("%ld",&n);
   while(n>0)
   {
   v = (long int*)malloc(n * sizeof(long int));
       SetVet(n, v);
       i = MaiorElem(n, v);
       printf("%ld %ld\n", i ,v[i]);
       free(v);
       scanf("%ld",&n );       
   }
   return 0;
}

void SetVet(long int n, long int* v)
{
   for(int i = 0; i < n; i++)
   {
       scanf("%ld", &v[i]);
   }
}

long int MaiorElem(long int n, long int* v)
{
   long int j = 0;
   for(long int i = 1; i < n; i++)
   {
       if(v[j] < v[i])
       {
           j = i;
       }
   }
   return j;
}
