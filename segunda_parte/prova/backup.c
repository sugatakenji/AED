#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
int verifica_ordena_cres(int* v, int n);
int verifica_ordena_decres(int* v, int n);
void imprime(int * v, int n);
int main()
{
    int n;                         // Tamanho do vetor
    int* v;		   // Ponteiro do vetor
    while( scanf("%d", &n) != EOF)
    {
        v = (int*) malloc( n * sizeof(int));
        preenche_vetor(v, n);
        if(0 == verifica_ordena_cres(v ,n) + verifica_ordena_decres(v, n))
        {
            printf("N\n");
        }else{
            printf("S\n");
        }
    }
    return 0;
}

void preenche_vetor(int* v, int n)
{
    for( int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            scanf("%d",v + i);
        }else{
            scanf("%d ", v + i);
        }
    }
}

int verifica_ordena_cres( int* v, int n)
{
    int i = 0;
    for( int j = 0; j < n; j++)
    {
        for( int i = j + 1; i < n; i++)
        {   
            if( v[j] > v[i])
            {
	return 0;
            }
        }
    }
    return 1;
}

int verifica_ordena_decres( int* v, int n)
{
    int i = 0;
    for( int j = 0; j < n; j++)
    {
        for( int i = j + 1; i < n; i++)
        {   
            if( v[j] < v[i])
            {
	return 0;
            }
        }
    }
    return 1;
}

void imprime(int* v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
