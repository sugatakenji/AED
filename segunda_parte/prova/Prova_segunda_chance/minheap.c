#include <stdio.h>
#include <stdlib.h>


struct Heap
{
    int* itens;
    int tamanho;
};
struct Heap criaHeap(int);
void constroiHeap(struct Heap*);
void peneira(struct Heap *h, int p);
int filhoEsquerda(int);
int filhoDireita(int);
int ultimoPai(int);



int main()
{
    struct Heap h;
    int n , i;
    scanf("%d", &n);
    while(n > 0)
    {
        h = criaHeap(n);
        for(i = 0; i< n; i++)
        {
            scanf("%d",&h.itens[i]);
        }
        constroiHeap(&h);
        for(i = 0;i < h.tamanho; i++)
        {
            printf("%d%s", h.itens[i], i<h.tamanho-1? " ":"\n");
        }      
        free(h.itens);
        scanf("%d", &n);
    }
    return 0;
}


struct Heap criaHeap(int n)
{
    struct Heap h;
    h.tamanho = n;
    h.itens = (int*) malloc(n * sizeof(int));
    return h;
}
void constroiHeap(struct Heap* h)
{
    int i;
    for(i=ultimoPai(h->tamanho); i>=0;i--)
    {
        peneira(h,i);
    }
}
void peneira(struct Heap *h, int p)
{
    int iMaior = p, aux;
    if(filhoDireita(p) < h->tamanho && h->itens[filhoDireita(p)] < h->itens[iMaior])
    {
        iMaior = filhoDireita(p);
    }
    if(filhoEsquerda(p) < h->tamanho && h->itens[filhoEsquerda(p)] < h->itens[iMaior])
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

