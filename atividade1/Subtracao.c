#include<stdio.h>

int subtracao(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", subtracao(a, b));
    return 0;
}

int subtracao(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return -1 + subtracao(a, b - 1);
}
