#include <stdlib.h>
#include <stdio.h>

typedef int TIPOCHAVE;

typedef struct estrutura
{
  TIPOCHAVE chave;
  NO * prox;
} NO;

typedef struct
{
  NO * inicio;
  NO * sentinela;
} LISTA;

void inicializarLista(LISTA * l)
{
  l->inicio = (NO *) malloc(sizeof(NO));
  /* Se lista vazia inicio == sentinela */
  l->sentinela = l->inicio;
}

void exibirLista(LISTA l)
{
  NO * atual = l.inicio;
  while (atual != l.sentinela)
  {
    printf("%d ", atual->chave);
    atual = atual->prox;
  }
}

NO * primeiroElemLista(LISTA l)
{
  if (l.inicio == l.sentinela) return NULL;
  else return l.inicio;
}

NO * ultimoElem(LISTA l)
{
  NO * atual = l.inicio;
  if (l.inicio == l.sentinela) return NULL;
  while (atual->prox != l.sentinela)
  {
    atual = atual->prox;
  }
  return atual;
}

NO * nesimoElemLista(LISTA l, int n)
{
  if (l.inicio == l.sentinela) return NULL;
  int contador = 1;
  NO * atual = l.inicio;
  while (atual != l.sentinela || contador < n)
  {
    atual = atual->prox;
    contador++;
  }
  if (contador<n) return NULL;
  else return atual;
}

int numELem(LISTA l)
{
  int contador = 1;
  NO * atual = l.inicio;
  if (l.inicio == l.sentinela) return 0;
  while (atual->prox != l.sentinela)
  {
    atual = atual->prox;
    contador++;
  }
  return contador;
}

NO * buscaSeqOrd(TIPOCHAVE ch, LISTA l, NO * *ant)
{
  NO * atual = l.inicio;
  * ant = NULL;
  l.sentinela->chave = ch;
  while (atual->chave != ch)
  {
    * ant = atual;
    atual = atual->prox;
  }
  if (atual != l.sentinela && atual->chave == ch) return atual;
  return NULL;
}

void anexarElemLista(TIPOCHAVE ch, LISTA * l)
{
  NO * ultimo = ultimoElem(*l);
  NO * novo = (NO *) malloc(sizeof(NO));
  novo->prox = l->sentinela;
  novo->chave = ch;
  if (!ultimo) 
  {
    l->inicio = novo;
  } else {
    ultimo->prox = novo;
  }
}

void destruirLista(LISTA * l)
{
  NO * atual = l->inicio;
  NO * aux = NULL;
  if (l->inicio == l->sentinela) return;
  while (atual != l->sentinela)
  {
    aux = atual;
    atual = atual->prox;
    free(aux);
  }
  free(l->sentinela);
}

int remocaoSeqOrd(TIPOCHAVE ch, LISTA * l)
{
  NO * ant;
  NO * itemASerRemovido;

  itemASerRemovido = buscaSeqOrd(ch, *l, &ant);
  if (!itemASerRemovido) return 0;
  if (!ant) l->inicio = itemASerRemovido->prox;
  else ant->prox = itemASerRemovido->prox;
  free(itemASerRemovido);
  return 1;
}

int main()
{
  return 0;
}