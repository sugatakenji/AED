#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int* v, int n);
int particiona(int* v, int n, int p);
void imprime_vetor(int* v, int n);
int main()
{
    int* v, n, p;
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    scanf("%d", &p);
    preenche_vetor(v, n);
    printf("\n%d\n",particiona(v, n, p));
    imprime_vetor(v, n);
    return 0;
}

int particiona(int* v, int n, int p)
{
    int pm = -1, aux, i ;
    aux = v[n-1];
    v[n-1] = v[p];
    v[p] = aux;
    for(i = 0; i < n -1 ; i++)
    {
        if(v[i] <= v[n-1])
        {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
        }
        
    }        
    aux = v[pm + 1];
    v[pm + 1] = v[n - 1];
    v[n - 1] = aux;
    return pm+1; 
   
}
void imprime_vetor(int* v, int n)
{
    for(int i = 0; i < n; i++)
    {
            printf("%d\n", v[i]);
    }
}
void preenche_vetor(int* v, int n)
{
    for(int i= 0; i < n ; i++)
    {
        scanf("%d",v + i);
    }
}
