#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int n);
int ordena_bubble(int* v, int n);

int main()
{
    int n, x;                         // Tamanho do vetor e alvo
    int* v;		   // Ponteiro do vetor
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int)); // aloca o vetor
    preenche_vetor(v, n);               //preenche o vetor com os dados lido no terminal
    printf("Trocas: %d\n", ordena_bubble(v, n));
    return 0;
}

int ordena_bubble(int* v, int n)
{
    int swap, troca = 0;
    imprime_vetor(v, n);
    for( int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(v[j] > v[j + 1])
            {
	swap = v[j];
	v[j] = v[j + 1];
	v[j + 1] = swap;
	troca++;
	imprime_vetor(v, n);
            }
        }
    }
    imprime_vetor(v, n);
    return troca;
}
void imprime_vetor(int* v, int n)
{
    for(int i = 0; i < (n - 1); i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n",v[n-1]);
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
