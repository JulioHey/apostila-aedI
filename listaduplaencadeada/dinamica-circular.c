#include <stdlib.h>
#include <stdio.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *ant;
  struct estrutura *prox;
} NO;

typedef struct {
  NO * cabeca;
} LISTA;

void inicializarLista(LISTA *l)
{
  l->cabeca = (NO *) malloc(sizeof(NO));

  l->cabeca->ant = l->cabeca;
  l->cabeca->prox = l->cabeca;
}

NO * ultimoElemLista(LISTA l)
{
  NO * ultimoElem = l.cabeca->ant;
  return ultimoElem == l.cabeca ? NULL : ultimoElem;
}

int inserirElemListaOrd(TIPOCHAVE ch, LISTA *l)
{
  NO * elem = l->cabeca->prox; 
  while (elem->chave < ch)
  {
    elem = elem->prox;
  }
  if (elem->chave == ch) return 0;

  NO * novoElemento = (NO *) malloc(sizeof(NO));

  elem->ant->prox = novoElemento;
  novoElemento->ant = elem->ant;
  elem->ant = novoElemento;
  novoElemento->prox = elem;
}

int excluirElemListaOrd(TIPOCHAVE ch, LISTA *l)
{
  NO * elem = l->cabeca->prox; 
  while (elem->prox != l->cabeca)
  {
    elem = elem->prox;
    if (elem->chave == ch) break;
  }
  if (elem->chave != ch) return 0;

  elem->ant->prox = elem->prox;
  elem->prox->ant = elem->ant;
  free(elem);
  return 1;
}

