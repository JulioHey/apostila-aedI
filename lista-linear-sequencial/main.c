#include <stdio.h>

#define MAX 50
#define VALOR_INVALIDO -1

#define true 1
#define false 0

typedef int TIPOCHAVE;
typedef int bool;

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

bool inserirElementoListaSeq(TIPOCHAVE ch, int i, LISTA * l)
{
  /* Não foi possivel inserir o elemento na posicao i */
  if (i > l->nmrElementos || i >= MAX) return false;
  int iterador;
  l->nmrElementos += 1;
  
  for (iterador = l->nmrElementos - 1; iterador >= i + 1; iterador--)
  {
    l->A[iterador].chave = l->A[iterador - 1].chave;
  }

  l->A[iterador].chave = ch;

  return true;
}

int buscaSequencial(TIPOCHAVE ch, LISTA l)
{
  int iterador;
  for (iterador = 0; iterador < l.nmrElementos; iterador++)
  {
    if (l.A[iterador].chave == ch) return iterador;
  }
  return VALOR_INVALIDO;
}

bool excluirElementoListaSeq(TIPOCHAVE ch, LISTA * l)
{
  int iterador = buscaSequencial(ch, *l);
  if (iterador == VALOR_INVALIDO) return VALOR_INVALIDO;

  l->nmrElementos -= 1;

  for (iterador; iterador < l->nmrElementos; iterador++)
  {
      l->A[iterador].chave = l->A[iterador+1].chave;
  }

  return true;
}

int buscaSent(TIPOCHAVE ch, LISTA l)
{
  int iterador = 0;
  l.A[l.nmrElementos].chave = ch;
  while (l.A[iterador].chave < ch) iterador++;
  if (iterador > l.nmrElementos - 1 || l.A[iterador].chave != ch) return VALOR_INVALIDO;
  return iterador;
}

int buscaBin(TIPOCHAVE ch, LISTA l)
{
  int limiteInferior, limiteSuperior, meio;
  limiteInferior = 0;
  limiteSuperior = l.nmrElementos - 1;
  while (limiteInferior <= limiteSuperior)
  {
    meio = ((limiteInferior + limiteSuperior) / 2);
    if (l.A[meio].chave == ch) return meio;
    else
    {
      if (l.A[meio].chave < ch) limiteInferior = meio + 1;
      else limiteSuperior = meio - 1;
    }
  }

  return VALOR_INVALIDO;
}

int main()
{
  LISTA minhaLista;

  inicializarLista(&minhaLista);
  imprimeLista(&minhaLista);

  inserirElementoListaSeq(1, 0, &minhaLista);
  inserirElementoListaSeq(2, 1, &minhaLista);
  inserirElementoListaSeq(3, 2, &minhaLista);
  inserirElementoListaSeq(4, 3, &minhaLista);
  
  imprimeLista(&minhaLista);

  printf("%d\n", minhaLista.nmrElementos);
  printf("%d\n", buscaSequencial(2, minhaLista));
  printf("%d\n", buscaSequencial(5, minhaLista));

  excluirElementoListaSeq(2, &minhaLista);

  imprimeLista(&minhaLista);
}