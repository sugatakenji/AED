#include <stdio.h>
#include <stdlib.h>

void preenche_vetor( int* v, int n);
int busca_binaria(int* v, int x, int n);
int main()
{
    int n, m, x; 
    int* v;
    scanf("%d", &n);
    v = (int *)malloc(n *(sizeof(int)));
    preenche_vetor(v, n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
         scanf("%d", &x);
         busca_binaria(v, x, n);
    }
    return 0;
}

void preenche_vetor(int* v, int n)
{
    for( int i = 0; i < (n - 1); i++)
    {
        scanf("%d ",( v + i ));

    }
    scanf("%d",(v + n - 1));
}

int busca_binaria( int* v, int x, int n)
{
    int esq = 0;
    int dir = n - 1;
    int meio;
    while(esq <= dir)
    {
        meio = (esq + dir) / 2;
        if(v[meio] == x)
        {
            printf("ACHEI\n");
            return 0;
        }else{
            if( x < v[meio])
            {
	dir = meio - 1;
            }else{
	esq = meio + 1;
            }
        }
    }
    printf("NAO ACHEI\n");
    return 0;
}
