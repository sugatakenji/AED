#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int *v, int n);
int busca_linear(int *v, int n, int m);

int main()
{
    int n, m, x;
    int* vetor;
    scanf("%d",&n);
    vetor = (int*) malloc( n * sizeof(int));
    preenche_vetor(vetor, n);
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        if( 1 == busca_linear( vetor, n, x))
        {
           printf("ACHEI\n");
        }else{
             printf("NAO ACHEI\n");
        }
    }
    return 0;
}

int busca_linear(int *v, int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        if( m == v[i])
        {
            return 1;
        }
    }
    return 0;
} 

void preenche_vetor(int* v, int n)
{
    for( int i = 0; i < (n - 1); i++)
    {
        scanf("%d ",(v+i));
    }
    scanf("%d",v+(n - 1));
}
