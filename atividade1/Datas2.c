#include <stdio.h>
int Bissexto(  int ano);
int VerificaData(int dia,  int mes,  int ano);
int main()
{
    int dia;
    int mes;
    int ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    if(VerificaData(dia, mes, ano))
    {
        printf("DATA VALIDA\n");
        return 0;
    }
    printf("DATA INVALIDA\n");
    return 0;
}

int VerificaData(  int dia,  int mes,  int ano)
{
//////////////////////////////////////////////////////
    if( mes > 12 || mes <= 0)
    {
        return 0;
    }
    if( dia > 31 || dia <= 0 )
    {
        return 0;
    }
//////////////////////////////////////////////////////////////
    switch(dia)
    {
        case 29:
            if(mes == 2){
	if(Bissexto(ano))
	{
	    return 1;
	}else
	{
	    return 0;
	}
            }else
            {
	return 1;
            }
            case 30:
            if( mes != 2)
            {
	return 1;
            }
            return 0;
        case 31:
            if( mes == 1 || mes == 3 || mes == 5 || mes == 7|| mes == 8 || mes == 10 || mes == 12)
            {
	return 1;
            }
            return 0;
    }
    return 1;
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
