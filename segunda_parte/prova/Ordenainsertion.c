#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
void inserction_sort(int* v, int n);
void imprime_vetor(int* v, int n);

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
    int chave, j, troca = 0, pior;
    pior = (n * (n - 1)) / 2;    
    imprime_vetor(v, n);
    for(int i = 1; i < n; i++)
    {
        chave = v[i];
        j = i - 1;
        while( j >= 0 && v[j] >= chave)
        {
            if(v[j] > chave)
            {
	 v[j + 1] = v[j];
                 v[j] = chave;
	 imprime_vetor(v, n);
	 troca++;
            }
            j = j - 1;
        }
    }
    imprime_vetor(v, n);
    printf("Trocas:%d\n", troca);
    if( troca == 0)
    {
        printf("MELHOR CASO\n");
    }else if(troca >= pior)
    {
        printf("PIOR CASO\n");
    }else{
        printf("CASO ALEATORIO\n");
    }
    
}

void imprime_vetor(int*v , int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n - 1]);
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
