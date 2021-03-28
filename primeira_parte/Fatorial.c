#include <stdio.h>

long int Fatorial(long int n);

int main()
{
    long int n;
    scanf("%ld", &n);
    printf("%ld\n", Fatorial(n));
    return 0;
}

long int Fatorial(long int n)
{
    if( n == 0)
    {
        return 1;
    }
    return n * Fatorial(n - 1);
}
