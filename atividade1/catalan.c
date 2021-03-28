#include <stdio.h>

int catalan(int n);

int main()
{
    int i;
    scanf("%d", &i);
    while( i != -1)
    {
        printf("%d\n",catalan( i ));
        scanf("%d", &i);
    }
    return 0;
}

int catalan(int n)
{
    if( n == 0)
    {
        return 1;
    }
    return  (((4 * n) - 2) * catalan( n - 1 ) / (n + 1)) ;
}

