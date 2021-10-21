#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE chave;
  struct estrutura *prox;
} NO;

typedef struct
{
  NO * inicio;
  NO * fim;
} FILA;

void printFilaD(FILA f)
{
  if (f.inicio == NULL) return;
  NO * atual = f.inicio;
  while (atual)
  {
    printf("%d ", atual->chave);
    atual = atual->prox;
  }
  printf("\n");
}

void inicializarListaD(FILA * f)
{
  f->fim = NULL;
  f->inicio = NULL;
}

int tamanhoFila(FILA f)
{
  int tamanho = 0;
  NO * p = f.inicio;
  while (p)
  {
    tamanho++;
    p = p->prox;
  }
  return tamanho;
}

void entrarFilaD(TIPOCHAVE ch, FILA * f)
{
  NO * novoNo = malloc(sizeof(NO));
  novoNo->chave = ch;
  novoNo->prox = NULL;
  if (f->fim)
  {
    f->fim->prox = novoNo;
  } else
  {
    f->inicio = novoNo;
  }
  f->fim = novoNo;
}

TIPOCHAVE sairFilaD(FILA * f)
{
  if (!f->inicio) return -1;
  TIPOCHAVE ch = f->inicio->chave;
  NO * aux = f->inicio;
  f->inicio = f->inicio->prox;
  free(aux);
  if (!f->inicio) f->fim = NULL;
  return ch;
}

int main()
{
  FILA jorge;

  TIPOCHAVE chave = 10;

  inicializarListaD (&jorge) ; //inicializa fila estática
  printFilaD(jorge);
  entrarFilaD(10, &jorge); //inserir novo elemento ao final
  printFilaD(jorge);
  entrarFilaD(20, &jorge); //inserir novo elemento ao final
  printFilaD(jorge);
  entrarFilaD(30, &jorge); //inserir novo elemento ao final
  printFilaD(jorge);
  entrarFilaD(40, &jorge); //inserir novo elemento ao final
  printFilaD(jorge);
  entrarFilaD(50, &jorge); //inserir novo elemento ao final
  printFilaD(jorge);

  sairFilaD(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFilaD(jorge);

  sairFilaD(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFilaD(jorge);

  sairFilaD(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFilaD(jorge);

  sairFilaD(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFilaD(jorge);

  sairFilaD(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFilaD(jorge);

  printf("Tamanho: %d\n", tamanhoFila(jorge));

  return 0;
}