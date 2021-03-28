#include <stdio.h>
#include <stdlib.h>

void DiaAnterior(int* dia,int* mes, int* ano);
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
    int n,m; // N é a quantidade de testes e M a quantidade de viagens no tempo;
    char* v;
    scanf("%d", &n);
    for( int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &hoje.dia, &hoje.mes, &hoje.ano);
        scanf("%d ", &m); //espaço para contar quebra de linha
        v = (char *)malloc(m * sizeof(char));
        for( int j = 0; j < m; j ++)
        {
            scanf("%c", (v + j));
        }
        for( int j = 0; j < m ; j ++)
        {
            if(v[j] == '<')
            {
	DiaAnterior( &hoje.dia, &hoje.mes, &hoje.ano);
            }else{
	DiaProximo( &hoje.dia, &hoje.mes, &hoje.ano);
            }
        }
      //  DiaProximo( &hoje.dia, &hoje.mes, &hoje.ano);
        printf("%d/%d/%d\n", hoje.dia, hoje.mes, hoje.ano);
    }
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
void DiaAnterior(int* dia, int* mes, int* ano)
{
    if( *dia == 1)
    {
        switch(*mes)
        {
            case 1:
	*dia = 31;
	*mes = 12;
	(*ano)--;
	break;
            case 2:
	*dia = 31;
	(*mes)-- ;
	 break;
            case 3:
	if(Bissexto(*ano))
	{
	    *dia = 29;
	    (*mes)-- ;
	}else{
	    *dia = 28;
	    (*mes)-- ;
	} 
	break;
            break;
            case 4:
	*dia = 31;
	(*mes)--;
            break;
            case 5:
	*dia = 30;
	(*mes)--;

            break;
            case 6:
	*dia = 31;
	(*mes)--;
            break;
            case 7:
            	*dia = 30;
	(*mes)--;
            break;
            case 8:
	*dia = 31;
	(*mes)--;
            break;
            case 9:
            	*dia = 31;
	(*mes)--;
            break;
            case 10:
	*dia = 30;
	(*mes)--;
            break;
            case 11:
	*dia = 31;
	(*mes)--;
            break;
            case 12:
	(*dia) = 30;
	(*mes)--;
            break;
        }
    }else{
        	(*dia)-- ;
    }
}
