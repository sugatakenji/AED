#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(float* v, int n);
int busca(float* v, int n, float x);

int main()
{
    int n, num, den;                         // Tamanho do vetor e alvo
    float* v;
    float x;		   // Ponteiro do vetor
    scanf("%d", &n);
    v = (float*) malloc(n * sizeof(float)); // aloca o vetor
    preenche_vetor(v, n);               //preenche o vetor com os dados lido no terminal
    while( scanf("%d %d", &num, &den) != EOF)     // aqui começa os testes
    {
        x = (float) num / den;
        busca(v, n, x);
    }
    return 0;
}

int busca(float* v, int n, float x)
{
    for(int i = 0; i < n; i++)
    {
        if(x == v[i])
        {
            printf("S\n");
            return 0;
        }
    }
    printf("N\n");
    return 0;
}

void preenche_vetor(float* v, int n)
{
    int num, dem;
    for( int i = 0; i < n; i++)
    {
        if(i == n - 1)
        {
            scanf("%d %d ", &num, &dem);
            v[i] = (float) num / dem;
        }else{
            scanf("%d %d", &num, &dem);
            v[i] = (float) num / dem;
        }
    }
}
