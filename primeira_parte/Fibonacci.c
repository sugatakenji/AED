#include <stdio.h>

int Fibonacci(int n);

int main()
{
     int n;
    scanf("%d", &n);
    printf("%d\n",Fibonacci(n));
    return 0;
}

 int Fibonacci( int n)
{
    if( n == 2 || n == 3)
    {
        return 1;
    }
    if( n == 1)  
    {
 	return 0;
    }
    return Fibonacci( n - 1) + Fibonacci( n - 2);
}
