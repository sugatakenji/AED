#include<stdio.h>

struct tComplex
{
    int x;
    int y;
};


struct tComplex soma(struct tComplex m1, struct tComplex m2);
struct tComplex complexo(int a, int b);
struct tComplex mult(struct tComplex m1, struct tComplex m2);
struct tComplex sub(struct tComplex m1, struct tComplex m2);
struct tComplex div(struct tComplex m1, struct tComplex m2);

int main()
{
    int a, b, c, d;
    struct tComplex m, m1, m2;
    char op, i;
    while(scanf("%d %d%c %c %d %d%c",&a, &b, &op, &op, &c, &d, &i) != EOF)
    {
        m1 = complexo( a, b);
        m2 = complexo( c, d);
        if( op == '+')
        {
            m  = soma( m1 , m2 );
	if( m.y >= 0)
            {
	printf("%d +%di\n", m.x, m.y);
            }else{
	 printf("%d %di\n", m.x, m.y); 
            } 
        }
        if( op == '-')
        {
            m  = sub( m1 , m2 );
	if( m.y >= 0)
            {
	printf("%d +%di\n", m.x, m.y);
            }else{
                printf("%d %di\n", m.x, m.y); 
            } 
        }
        if( op == '*')
        {
            m  = mult( m1 , m2 );
	if( m.y >= 0)
            {
	printf("%d +%di\n", m.x, m.y);
            }else{
	 printf("%d %di\n", m.x, m.y); 
            } 
        }
        if( op == '/')
        {
            m  = div( m1 , m2 );
	if( m.y >= 0)
            {
	printf("%d +%di\n", m.x, m.y);
            }else{
	 printf("%d %di\n", m.x, m.y);  
            }
        }
    }
    

    return 0;
}

struct tComplex complexo(int a, int b)
{
    struct tComplex c = { a, b };
    return c;
}

struct tComplex soma(struct tComplex m1, struct tComplex m2)
{
    struct tComplex m;
    m.x = m1.x + m2.x;
    m.y = m1.y + m2.y;
    return m;
}

struct tComplex sub(struct tComplex m1, struct tComplex m2)
{
    struct tComplex m;
    m.x = m1.x - m2.x;
    m.y = m1.y - m2.y;
    return m;
   

} 
struct tComplex mult(struct tComplex m1, struct tComplex m2)
{
    struct tComplex m;
    m.x = ( m1.x * m2.x) + ( m1.y * m2.y * -1);
    m.y = ( m1.x * m2.y) + ( m1.y * m2.x);
    return m;
}

struct tComplex div(struct tComplex m1, struct tComplex m2)
{
    struct tComplex m;
    int a, b, c;
    c = (m2.x * m2.x) + (m2.y * m2.y) ;
    a = (m1.x * m2.x) + (m1.y * m2.y);
    b = (m2.x * m1.y) - (m1.x * m2.y);
    m.x = a / c;
    m.y = b / c;
    return m;
}
