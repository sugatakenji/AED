#include <stdio.h>

int main()
{
    int soma = 0, valor;
    while(scanf("%d", &valor) != EOF)
    {
        soma = soma + valor;
    }
    printf("%d\n", soma);
    return 0;
}
