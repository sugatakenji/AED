#include <stdio.h>
#include <stdlib.h>

void SetVet(int n, int* v);
int Energia(int n, int k, int* v);

int main()
{
    int n, k;
    int* v;
    scanf("%d", &n);
    scanf("%d", &k);
    v = (int*)malloc(n * sizeof(int));
    SetVet(n, v);
    printf("%d\n", Energia(n, k , v));
    return 0; 
}

void SetVet( int n, int* v)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

int Energia(int n, int k, int* v)
{
    int E = 100;
    int i = 0;
    i = (i + k) % n;
    E -= 1 + 2 * v[i];
    while(i)
    {
         i = (i + k) % n;
         E -= 1 + 2 * v[i];
    }
    return E;
}
