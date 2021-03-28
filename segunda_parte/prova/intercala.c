#include <stdio.h>
#include <stdlib.h>
void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int n);
void intercala(int* vu, int* vaux,int q3);
int menor(int* v, int i, int f);
int main()
{
    int q1, q2, q3;
    int* vu,* vaux;
    scanf("%d",&q1);
    scanf("%d",&q2);
    q3 = q1 + q2;
    vu = (int*) malloc(q3 * sizeof(int));
    preenche_vetor(vu, q3);
    vaux = (int*) malloc(q3 * sizeof(int));
    intercala2(vu, vaux, q3);
    imprime_vetor(vaux, q3);
    return 0;
}

int menor(int* v, int i, int f)
{
    int m = i;
    for( int j = i; j < f; j++)
    {
       if( v[m] > v[j])
        {
            m = j;
        }
    }
    return m;
}

void intercala2(int* vu, int* vaux,int q3)
{
    int m;
    for(int i = 0; i < q3; i++)
    {
      m = menor( vu, i, q3);
      vaux[i] = vu[m];
    }
      
}


void imprime_vetor(int*v , int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }
}

void preenche_vetor(int* v, int n)
{
    for( int i = 0; i < n; i++)
    {
            scanf("%d",v + i);
    }
}
