
#include <stdio.h>
#include <stdlib.h>

void qSort(int *, int);
void quickSort(int *, int, int, int);
int particiona(int *, int, int, int);

int main()
{
    int n, *v, i;

    while(scanf("%d", &n) != EOF)
    {
        v = (int*) malloc(n * sizeof(int));

        for(i=0; i<n; i++)
        {
            scanf("%d", &v[i]);
        }

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], i<n-1?" ":"\n");
        }

        qSort(v, n);

        for(i=0; i<n; i++)
        {
            printf("%d%s", v[i], i<n-1?" ":"\n");
        }
        free(v);
    }
    return 0;
}

void qSort(int *v, int n)
{
    quickSort(v, 0, n-1, n);
}

void quickSort(int *v, int e, int d, int n)
{
    int p;
    if(e < d)
    {
        p = particiona(v, e, d, n);
        quickSort(v, e, p-1, n);
        quickSort(v, p+1, d, n);
    }
}

int particiona(int *v, int e, int d, int n)
{
    int i, pm, aux, j;
    for(i=e, pm=e-1; i<d; i++)
    {
        if(v[i] <= v[d])
        {
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
     for(j=0; j<n; j++)
    {
            printf("%d%s", v[j], j<n-1?" ":"\n");
    }

    }
    aux = v[pm+1];
    v[pm+1] = v[d];
    v[d] = aux;
    for(i=0; i<n; i++)
    {
            printf("%d%s", v[i], i<n-1?" ":"\n");
    }


    return pm+1;
}
