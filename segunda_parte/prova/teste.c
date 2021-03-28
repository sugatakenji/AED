#include <stdio.h>
#include <stdlib.h>

struct Racional
{
    int numerador;
    int denominador;
    float racional;  
};

void construtor(struct Racional* racional, int n, int d);
void preenche_vetor( float
int main()
{
    struct Racional racional;
    construtor(&racional, 5, 2);
    printf("%f\n", racional.racional);
    return 0;
}

void construtor(struct Racional* racional, int n, int d)
{
    racional->numerador = n;
    racional->denominador = d;
    racional->racional =(float) n / d;
}
