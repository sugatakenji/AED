#include<stdio.h>

int adicao(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", adicao(a, b));
    return 0;
}

int adicao(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return 1 + adicao(a, b - 1);
}
