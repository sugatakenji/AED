#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int* v, int n);
int particiona(int* v, int e, int d, int n);
void quicksort(int* v, int e, int d, int n);
void imprime_vetor(int* v, int n);
int main()
{
    int* v, n ;
    scanf("%d", &n);
    v = (int*)malloc(n * sizeof(int));
    preenche_vetor(v, n);
    quicksort(v, 0, n-1, n);
    return 0;
}

void quicksort(int* v, int e, int d, int n)
{
    int p;
    if( e <d)
    {
        
        p = particiona(v, e, d, n);
        quicksort(v, e, p - 1, n);
        quicksort(v,p, d, n);
    }
}

int particiona(int* v, int e, int d, int n)
{
    int pm =e -1, aux, i ;
    for(i = e; i < d ; i++)
    {
        if(v[i] <= v[d])
        {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;

    imprime_vetor(v, n);
        }
        
    
    }        
    aux = v[pm + 1];
    v[pm + 1] = v[d];
    v[d] = aux;
     if(pm+1 != d)
    { 
    imprime_vetor(v, n);
    }
    return pm+1; 
   
}
void imprime_vetor(int* v, int n)
{
    for(int i = 0; i < n; i++)
    {
            printf("%d%s", v[i], i == n-1 ? "\n":" ");
    }
}
void preenche_vetor(int* v, int n)
{
    for(int i= 0; i < n ; i++)
    {
        scanf("%d",v + i);
    }
}
