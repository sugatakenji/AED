#include <stdio.h>

int DivisaoIn(int a, int b);

int main()
{
     int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n",DivisaoIn(a,b));
    return 0;
}

int DivisaoIn( int a, int b)
{
    if( a < b)
    {
        return 0;
    }
    return 1 + DivisaoIn(a - b, b);
}
