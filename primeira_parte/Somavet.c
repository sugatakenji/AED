#include <stdio.h>
#include <stdlib.h>

long int Vetorx3(long int* vetor, long int tamanho);

int main()
{
   long int n;
   long int *v;
   scanf("%ld", &n);
   v = (long int*)malloc(n * sizeof(long int));
   Vetorx3(v, n);
   for ( int i = 0; i < n; i++)
   {
       printf("%ld ", v[i]);
   }
   printf("\b\n");
   return 0;
}

long int Vetorx3(long int* vetor, long int tamanho)
{
   for(int i = 0; i < tamanho; i++)
   {
       scanf("%ld", &vetor[i]);
   }
   for(int i = 0; i < tamanho; i++)
   {
       vetor[i] = vetor[i] * 3;
   }
   return 0;
}
