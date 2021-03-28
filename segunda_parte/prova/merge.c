#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int n);
void intercala(int* v, int e,int meio,int d);
void merge(int*v, int e, int d);
int main()
{
    int n;
    int* v;
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    preenche_vetor(v, n );
   intercala(v, 0, 0, 1);
 //  merge(v, 0, n-1);    
    imprime_vetor(v, n);
    return 0;
}

void merge(int* v, int e, int d)
{
    int meio;
    if(e < d)
    {
        meio = (e + d)/2;
        merge(v, e, meio);
        merge(v, meio + 1, d);
        printf("e=%d m=%d d=%d intercala: ",e ,meio, d);
       intercala(v, e, meio , d); 
         imprime_vetor(v, 4);
    }
}

void intercala(int* v, int e, int meio, int d)
{
    int* temp;
    int i ;
    int fim_esq = meio - 1;
    if( e == meio)
    {
        fim_esq = meio;
        printf("é sim\n");
    }
    temp = (int*)malloc( d * sizeof(int));
    for(i = e ; e <=fim_esq && meio< d; i++) /////
    {
        if(v[e] < v[meio])
        {
            temp[i] = v[e];
            e++;
        }else{
            temp[i] = v[meio];
            meio++;
        }
    }
    for(;e <= fim_esq;e++,i++)
    {
        temp[i] = v[e];
    }
    for(; meio<d;meio++,i++)
    {
        temp[i] = v[meio];
    }
    for(i = 0; i<d;i++)
    {
        v[i] = temp[i];
    }
    free(temp);
}

void imprime_vetor(int*v , int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n -1]);
}

void preenche_vetor(int* v, int n)
{
    for( int i = 0; i < n - 1; i++)
    {
            scanf("%d ",v + i);
    }
    scanf("%d",v + n - 1);
}
