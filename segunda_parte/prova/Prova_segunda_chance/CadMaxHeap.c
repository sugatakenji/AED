#include <stdio.h>
#include <stdlib.h>


struct Heap
{
    int* itens;
    int tamanho;
    int ultimoElemento;
};
void mostraHeap(struct Heap);
void insereHeap(struct Heap*, int );
void removeHeap(struct Heap*); 

struct Heap criaHeap(int);
void constroiHeap(struct Heap*);
void peneira(struct Heap *h, int p);
int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);



int main()
{
    struct Heap h;
    int n , e;
    char op;
    scanf("%d", &n);
    h = criaHeap(n);
    while(scanf("\n%c", &op) != EOF)
    {
        if(op == 'I')
        {
            scanf(" %d", &e);
            insereHeap(&h, e);
        }
        if(op == 'M')
        {
            mostraHeap(h);
        }
        if(op == 'R')
        {
            removeHeap(&h);
        }
    }
    return 0;
}

void mostraHeap(struct Heap h)
{
    int i;
    if(h.ultimoElemento == -1)
    {
        return;
    }else{
        for(i = 0; i <=h.ultimoElemento;i++)
        {
            printf("%d%s", h.itens[i], i==h.ultimoElemento? "\n":" ");
        } 
    }
}
void insereHeap(struct Heap* h, int e )
{
    if(h->ultimoElemento == h->tamanho - 1)
    {
        return;
    }else{
        h->itens[h->ultimoElemento + 1] = e;
        h->ultimoElemento++;
    }
    constroiHeap(h);
}
void removeHeap(struct Heap* h)
{
    if(h->ultimoElemento <=-1 )
    {
        return;
    }else{
        printf("%d\n",h->itens[0]);
        h->itens[0] = h->itens[h->ultimoElemento];
        h->itens[h->ultimoElemento] = -1;
        constroiHeap(h);
        h->ultimoElemento--;
    }
} 


struct Heap criaHeap(int n)
{
    struct Heap h;
    h.tamanho = n;
    h.itens = (int*) malloc(n * sizeof(int));
    h.ultimoElemento = -1;
    return h;
}
void constroiHeap(struct Heap* h)
{
    int i;
    for(i=ultimoPai(h->ultimoElemento + 1 ); i>=0;i--)
    {
        peneira(h,i);
    }
}
void peneira(struct Heap *h, int p)
{
    int iMaior = p, aux;
    if(filhoDireita(p) < (h->ultimoElemento + 1) && h->itens[filhoDireita(p)] > h->itens[iMaior])
    {
        iMaior = filhoDireita(p);
    }
    if(filhoEsquerda(p) < (h->ultimoElemento + 1) && h->itens[filhoEsquerda(p)] > h->itens[iMaior])
    {
        iMaior = filhoEsquerda(p);
    }
    if(iMaior != p)
    {
        aux = h->itens[p];
        h->itens[p] = h->itens[iMaior];
        h->itens[iMaior] = aux;
        peneira(h, iMaior);
    }
}
int filhoEsquerda(int p)
{
    return 2*p+1;
}
int filhoDireita(int p)
{
    return 2*p + 2;
}
int ultimoPai(int n)
{
    return n/2 - 1;
}

