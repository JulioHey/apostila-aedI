#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct estrutura
{
  TIPOCHAVE ch;
  struct estrutura * prox;
} NO;

typedef struct 
{
  NO * cabeca;
  NO * topo;
} PILHAD;


void inicializarPilhaD(PILHAD * p)
{
  p->topo = NULL;
}

int tamanhoPilhaD(PILHAD p)
{
  int contador = 0;
  NO * atual = p.topo;
  
  while (atual->prox)
  {
    contador++;
    atual = atual->prox;
  }

  return contador;
}

void push(TIPOCHAVE ch, PILHAD * p)
{
  NO * novo = (NO *) malloc(sizeof(NO));
  novo->ch = ch;

  novo->prox = p->topo;
  p->topo = novo;
}

TIPOCHAVE pop(TIPOCHAVE ch, PILHAD * p)
{
  if (!p->topo) return -1;
  NO * ultimo = p->topo;
  TIPOCHAVE ch = p->topo->ch;

  p->topo = p->topo->prox;
  free(ultimo);
  return ch;
}

int main()
{

}