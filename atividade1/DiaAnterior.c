#include <stdio.h>

void DiaAnterior(int* dia,int* mes, int* ano);
int Bissexto( int ano);

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
    DiaAnterior( &hoje.dia, &hoje.mes, &hoje.ano);
    printf("%d %d %d\n", hoje.dia, hoje.mes, hoje.ano);
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

