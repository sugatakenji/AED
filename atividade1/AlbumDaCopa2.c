#include<stdio.h>
#include<stdlib.h>

void SetVet(int n,  int* v);
int Verifica(int n, int m, int* v);
int main()
{
    int N, M;
    int* vm;
    scanf("%d", &N);
    scanf("%d", &M);
    vm = (int*)malloc(M * sizeof(int));
    SetVet( M, vm);
    printf("%d\n", Verifica( N, M, vm)); 
   return 0;
}

int Verifica(int n, int m, int*v)
{
    int count = 0;
    for( int i = 1; i <= n; i++)
    {
        for( int j = 0; j < m; j++)
        {
            if( i == v[j])
            {
	count += 1;
	j = m;
            }
        }
    }
    return n - count;
}
void SetVet( int n,  int* v)
{
   for(int i = 0; i < n; i++)
   {
       scanf("%d", &v[i]);
   }
}


