#include <stdio.h>

int Bissexto( int ano);
void DiaProximo(int* dia, int* mes, int* ano);
    
int main()
{
    struct data
    {
        int dia;
        int mes;
        int ano;
    };
    struct data hoje;
    scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
    DiaProximo( &hoje.dia, &hoje.mes, &hoje.ano);
    printf("%d %d %d\n", hoje.dia, hoje.mes, hoje.ano);
}   

void DiaProximo(int* dia, int* mes, int* ano)
{
    if(*dia == 31)
    {
        *dia = 1;
        if( *mes == 12)
        {
            *mes = 1;
            *ano += 1;
        }else{
            *mes += 1;
        }
    }else if( *dia == 30)
    {
        if( *mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12 )
        {
            *dia += 1;
        }else{
            *mes += 1;
            *dia = 1;
        } 
    }else if( *dia == 28 && *mes == 2)
    {
        if(Bissexto(*ano))
        {
            *dia += 1;
        }else{
            *dia = 1;
            *mes += 1;
        }
    }else if( *dia == 29 && *mes == 2)
    {
        *dia = 1;
        *mes +=1;
    }else{
        *dia += 1;
    }
}
int Bissexto( int ano)
{
    if( ano % 400 == 0)
    {
        return 1;  
    }else if( ano % 100 == 0 )
            {
                return 0;
           }else if( ano % 4 == 0)
                    {
                       return 1;
                    }else
                    {
                       return 0;
                    }
}

