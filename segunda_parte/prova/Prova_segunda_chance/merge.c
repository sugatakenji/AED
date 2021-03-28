#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int* v, int n);
void imprime_vetor(int* v, int n);
void intercala(int* v,int e,int m,int d); 
void merge_sort(int* v, int e, int d, int n);
int traduz(int marciano);
int main()
{
    int *v, e, m, d, n;
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    preenche_vetor(v, n);
    imprime_vetor(v, n);
    merge_sort(v, 0, n - 1, n);
    imprime_vetor(v, n);
    return 0;
}

int traduz(int marciano)
{
    int terraqueo, aux =0;  
    for(int i = 10; i <= 1000; i * 10)
    {
       aux = marciano % i;
       aux = aux/(i/10);
       switch( aux)
       {
            case 0: 
	aux = 0;
	break;
            case 5: 
	aux = 1;
	break;
            case 6: 
	aux = 2;
	break;	
            case 4: 
	aux = 3;
	break;
            case 8: 
	aux = 4;
	break;
            case 9: 
	aux = 5;
	break;
            case 7: 
	aux = 6;
	break;
            case 3: 
	aux = 7;
	break;
            case 1: 
	aux = 8;
	break;
            case 2:
	 aux = 9;
	break;
       } 
        terraqueo+= aux*(i/10);
    }
    return terraqueo;
}

void merge_sort(int*v ,int e, int d, int n)
{
    int meio;
    if(e < d)
    {
        meio = (e + d) / 2;
        merge_sort(v, e, meio, n);
        merge_sort(v, meio + 1, d, n);
        imprime_vetor(v, n);
        intercala(v, e, meio + 1, d);
    }

}

void intercala(int* v, int e, int m, int d)
{
    int* temp, i, j, tamanho, fim_esq = m - 1, itemp;
    tamanho = d - e + 1;
    temp = (int*) malloc(tamanho * sizeof(int));
    for(i = e,  j = m, itemp= 0; i <= fim_esq && j <= d; itemp++)
    {
        if(v[i] < v[j])
        {
            temp[itemp] = v[i];
            i++;
        }else
        {
            temp[itemp] = v[j];
            j++;
        }
    }
    for(;i <= fim_esq; i++, itemp++)
    {
        temp[itemp] = v[i];
    }
    for(;j <= d; j++, itemp++)
    {
        temp[itemp] = v[j];
    }
    for(i = e, j = 0; i <= d; i++, j++)
    {
        v[i] = temp[j];
    }
}


void preenche_vetor(int* v, int n)
{
    int i;
    for( i=0; i < n; i ++)
    {
        scanf("%d", v + i);
    }
    
}

void imprime_vetor(int* v, int n)
{
    int i;
    for( i = 0; i < n; i ++)
    {
        printf("%d%s", v[i], i == (n - 1)? "\n":" ");
    } 
}
