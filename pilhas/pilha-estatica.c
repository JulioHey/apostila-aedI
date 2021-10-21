#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE ch;
} REGISTRO;

typedef struct 
{
  int topo;
  REGISTRO A[MAX];
} PilhaE;

void inicializarPilhaE(PilhaE * p)
{
  p->topo = -1;
}

int tamanhoPilhaE(PilhaE p)
{
  return p.topo + 1;  
}

int pilhaCheia(PilhaE p)
{
  if (p.topo == MAX - 1) return 1;
  else return 0;
}

int push(TIPOCHAVE ch, PilhaE * p)
{
  if (pilhaCheia(*p)) return 0;
  p->topo++;
  p->A[p->topo].ch = ch;
  return 1; 
}

int pop(PilhaE * p)
{
  if (tamanhoPilhaE < 0) return -1;
  TIPOCHAVE ch = p->A[p->topo].ch;
  p->topo--;
  return ch; 
}