#include<stdio.h>

long int multiplicacao(long int a, long int b);

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    printf("%ld\n",multiplicacao(a, b));
    return 0;
}

long int multiplicacao(long int a, long int b)
{
    if(b == 0)
    {
        return 0;
    }
    if(b == 1)
    {
        return a;
    }
    return a + multiplicacao(a, b - 1);
}
