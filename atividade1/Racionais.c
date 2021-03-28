#include<stdio.h>

struct tRacional
{
    int numerador;
    int denominador;
};

struct tRacional racional(int numerador, int denominador);
struct tRacional negativo(struct tRacional r);
struct tRacional soma(struct tRacional r1, struct tRacional r2);
struct tRacional mult(struct tRacional r1, struct tRacional r2);
struct tRacional div(struct tRacional r1, struct tRacional r2);
struct tRacional reduz(struct tRacional r);




int main()
{
    struct tRacional  r1, r2, r3, r4, r5;
    int numerador1, denominador1, numerador2, denominador2;
    char operador;
    while( scanf("%d %d %c %d %d", &numerador1, &denominador1, &operador, &numerador2, &denominador2) != EOF)
    {
        r1 = racional(numerador1, denominador1);
        r2 = racional(numerador2, denominador2);
        if( operador  == '*'){
            r3 = mult( r1, r2 );
            r4 = reduz(r3);
            printf("%d %d\n", r4.numerador, r4.denominador);
        }
        if( operador  == '+'){
            r3 = soma( r1, r2 );
            r4 = reduz( r3 ); 
            printf("%d %d\n", r4.numerador, r4.denominador);
        }
        if( operador == '/' ){
            r3 = div( r1, r2 );
            r4 = reduz( r3 );
            printf("%d %d\n", r4.numerador, r4.denominador);
        }
        if( operador == '-' ){
            r5 = negativo( r2 );
            r3 = soma( r1, r5 ); // soma do negativo
            r4 = reduz( r3 );
            printf("%d %d\n", r4.numerador, r4.denominador);
        }
    }
    return 0;
}

struct tRacional racional(int numerador, int denominador)
{
    struct tRacional r = { numerador, denominador };
    return r;
}

struct tRacional negativo(struct tRacional r)
{
    struct tRacional rn = { -r.numerador, r.denominador };
    return rn;
}

struct tRacional soma(struct tRacional r1, struct tRacional r2)
{
    struct tRacional soma;
    soma.denominador = r1.denominador * r2.denominador;
    soma.numerador = r2.denominador * r1.numerador + r1.denominador * r2.numerador;
    return soma;
}

struct tRacional mult(struct tRacional r1, struct tRacional r2)
{
    struct tRacional mult;
    mult.denominador = r1.denominador * r2.denominador;
    mult.numerador = r1.numerador * r2.numerador;
    return mult;
}

struct tRacional div(struct tRacional r1, struct tRacional r2)
{
    struct tRacional div;
    div.denominador = r1.denominador * r2.numerador;
    div.numerador = r1.numerador * r2.denominador;
    return div;
}

struct tRacional reduz(struct tRacional r)
{
    //mdc por euclides
    struct tRacional fat;
    int mdc, resto, a, b;
    a = r.numerador;
    b = r.denominador;
    resto = a % b;
    mdc =  b ;
    while(resto)
    {
        a = b;
        b = resto;
        mdc = b;
        resto = a % b;    
    }
    //
    if( mdc < 0 ){ mdc *= -1; } //corrigi o mdc para positivo  
    fat.numerador = r.numerador / mdc;
    fat.denominador = r.denominador / mdc;
    return fat;
}
