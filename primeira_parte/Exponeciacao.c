#include <stdio.h>

long int Exponenci(long int a,long int b);

int main()
{
    long int a, b;
    scanf("%ld %ld", &a, &b);
    printf("%ld\n",Exponenci(a,b));
    return 0;
}

long int Exponenci(long int a,long int b)
{
    if( b == 0)
    {
        return 1;
    }
    return a * Exponenci(a , b - 1);
}
