#include<stdio.h>
#include<stdlib.h>

void SetVet(long int n, long int* v);
long int MenorSalto(long int n, long int* v);

int main()
{
   long int n, saltos;
   long int *v;
   scanf("%ld",&n);
   v = (long int *)malloc(n * sizeof(long int));
   SetVet(n , v);   
   saltos = MenorSalto(n , v);
   printf("%ld\n", saltos);
   return 0;
}



void SetVet(long int n, long int* v)
{
   for(int i = 0; i < n; i++)
   {
       scanf("%ld", &v[i]);
   }
}

long int MenorSalto(long int n, long int* v)
{
    long int saltos = 0;
    for( int i = 0; i < n - 1;)
    {
        if(v[i+2] == 0)
        {
	i += 2;
        }else
        {
             i += 1;
        }
	saltos++;
    }
    return saltos;
}
