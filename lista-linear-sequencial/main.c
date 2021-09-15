#include <stdio.h>

#define MAX 50
#define VALOR_INVALIDO -1

typedef int TIPOCHAVE;

typedef struct 
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct 
{
  REGISTRO A[MAX];
  int nmrElementos;
} LISTA;


int primeiroElemento(LISTA l)
{
  return l.nmrElementos > 0 ? l.A[0].chave : VALOR_INVALIDO;
}

int ultimoElemento(LISTA l)
{
  return l.nmrElementos > 0 ? l.A[l.nmrElementos].chave : VALOR_INVALIDO;
}  

int nesimoElemento(LISTA l, int n)
{
  return l.nmrElementos <= n ? l.A[n-1].chave : VALOR_INVALIDO;
}

void destruirLista(LISTA * l)
{
  l->nmrElementos = 0;
}

void inicializarLista(LISTA * l)
{
  l->nmrElementos = 0;
}

int tamanhoDaLista(LISTA * l)
{
  return l->nmrElementos;
}

void imprimeLista(LISTA * l)
{
  int i;
  for (i = 0; i < l->nmrElementos; i++)
  {
      printf("%d ", l->A[i].chave);
  }
  if (l->nmrElementos == 0) printf("LISTA VAZIA");
  printf("\n");
}

int main()
{
  LISTA minhaLista;

  inicializarLista(&minhaLista);
  int tam = tamanhoDaLista(&minhaLista);
  imprimeLista(&minhaLista);

  printf("%d\n", tam);
}