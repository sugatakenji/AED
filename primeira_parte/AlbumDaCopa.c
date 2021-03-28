#include<stdio.h>
#include<stdlib.h>

void SetVet(long int n, long int* v);
long int Compara(long  int* vc, long int* vm, long int C, long int M); 

int main()
{
   long int N, C, M, F;
   long int* vc, * vm;
   
   scanf("%ld %ld %ld", &N, &C, &M);
   vc = (long int*)malloc(C * sizeof(long int));
   vm = (long int*)malloc(M * sizeof(long int));
   SetVet(C, vc);
   SetVet(M, vm);
   F = Compara(vc, vm, C, M);
   printf("%ld\n", F);
   return 0;
}

long int Compara(long  int* vc, long int* vm, long int C, long int M) 
{
   int F = C;
   for ( int i = 0; i < C; i++)
   {
       for( int j = 0; j < M; j++)
       {
           if( vc[i] == vm[j])
           {
               F--;
	       j = M;
           }
       } 
   }
   return F;
}

void SetVet(long int n, long int* v)
{
   for(int i = 0; i < n; i++)
   {
       scanf("%ld", &v[i]);
   }
}


