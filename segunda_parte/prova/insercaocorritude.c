#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int i, int f);
void inserction_sort(int* v, int n);

int main()
{
    int n, x;                         // Tamanho do vetor e alvo
    int* v;		   // Ponteiro do vetor
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int)); // aloca o vetor
    preenche_vetor(v, n);               //preenche o vetor com os dados lido no terminal
    inserction_sort(v, n);    
    return 0;
}

void inserction_sort(int* v, int n)
{
    int chave, j;
    for(int i = 1; i < n; i++)
    {
        printf("Sublista Ordenada: ");
        imprime_vetor( v, 0, (i - 1));
        printf("Sublista Desordenada: ");
        imprime_vetor(v, i, (n - 1));
        chave = v[i];
        j = i - 1;
        while( j >= 0 && v[j] >= chave)
        {
            v[j + 1] = v[j];
            v[j] = chave;
            j = j - 1;
        }
    }
    printf("Sublista Ordenada: ");
    imprime_vetor( v, 0, (n - 1));
    printf("Sublista Desordenada:\n");
}

void imprime_vetor(int* v, int i, int f)
{
    
    for(int j = i; j < f ; j++)
    {
        printf("%d ", v[j]);
    }
    printf("%d\n",v[f]);
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
