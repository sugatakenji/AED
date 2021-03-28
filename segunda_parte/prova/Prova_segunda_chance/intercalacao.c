#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int n);
void intercala(int* v,int e,int m,int d); 
int main()
{
    int *v, e, m, d, n;
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    preenche_vetor(v, n);
    intercala(v, 0, n/2, n);
    imprime_vetor(v, n);
    return 0;
}

void intercala(int* v, int e, int m, int d)
{
    int* temp, i, fim_esq = m - 1;
    temp = (int*) malloc(d * sizeof(int));
    for(i = 0; e <= fim_esq && m < d; i++)
    {
        if(v[e] < v[m])
        {
            temp[i] = v[e];
            e++;
        }else
        {
            temp[i] = v[m];
            m++;
        }
    }
    for(;e <= fim_esq; e++, i++)
    {
        temp[i] = v[e];
    }
    for(;m < d; m++, i++)
    {
        temp[i] = v[m];
    }
    for(i = 0; i < d; i++)
    {
        v[i] = temp[i];
    }
}


void preenche_vetor(int* v, int n)
{
    int i;
    for( i=0; i < n; i ++)
    {
        scanf("%d", v + i);
    }
    
}

void imprime_vetor(int* v, int n)
{
    int i;
    for( i = 0; i < n; i ++)
    {
        printf("%d%s", v[i], i == (n - 1)? "\n":" ");
    } 
}
