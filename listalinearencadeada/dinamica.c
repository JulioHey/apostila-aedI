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
} LISTA;

NO * buscaSeqOrd(TIPOCHAVE ch, LISTA l, NO * ant)
{
  /* Variavel auxiliar para iterarmos através da lista */  
  NO * atual = l.inicio;
  /* Condição de parada, chegamos no fim da lista */
  while (atual != NULL)
  {
    /* Caso acharmos algum número menor ou igual significa que ou
    não existe esse número na lista ou ele ja exite por isso
    por isso paramos o loop */
    if (atual->chave >= ch) break;
    /* Setamos o anterior para o antigo atual */
    ant = atual;
    /* Atualizamos o atual */
    atual = atual->prox;
  }
  /* atual é diferente de NULL, se sim sim */
  if (atual)
  {
    /* chave atual é a chave que estamos procurando?*/
    if (atual->chave == ch) return atual;
  }
  /* Ou chegamos ao fim da lista, ou achamos uma chave maior
  sem passar pela chave que estamos procurando */
  return NULL;
}

int inserirElemListaOrd(TIPOCHAVE ch, LISTA * l)
{
  NO * ant;
  NO * novo;

  novo = buscaSeqOrd(ch, *l, &ant);

  if (novo) return 0;
  novo = (NO *) malloc(sizeof(NO));
  novo->chave = ch;

  if (!l->inicio)
  {
    l->inicio = novo;
    novo->prox = NULL;
  }
  else 
  {
    if (!ant)
    {
      novo->prox = l->inicio;
      l->inicio = novo;
    }
    else
    {
      {
        novo->prox = ant->prox;
        ant->prox = novo;
      }
    }
  }

  return 1;
}

void anexarElemLista(TIPOCHAVE ch, LISTA * l)
{
  NO * ant;
  NO * novo;
  while (ant != NULL)
  {
    if (ant->prox == NULL) break;
    ant = ant->prox;
  }
  novo = (NO *) malloc(sizeof(NO));
  novo->chave = ch;
  novo->prox = NULL;
  ant->prox = novo;
}

int remocaoSeqOrd(TIPOCHAVE ch, LISTA * l)
{
  NO * ant;
  NO * itemASerRemovido;

  itemASerRemovido = buscaSeqOrd(ch, *l, &ant);
  /* Não achamos a chave que devemos deletar */
  if (!itemASerRemovido) return 0;
  if (!ant) l->inicio = itemASerRemovido->prox;
  else ant->prox = itemASerRemovido->prox;
  free(itemASerRemovido);
}

