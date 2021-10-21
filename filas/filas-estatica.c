#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef int TIPOCHAVE;

typedef struct estrutura {
  TIPOCHAVE ch;
} REGISTRO;

typedef struct
{
  REGISTRO A[MAX];
  int inicio;
  int fim;
} FILA;

void printFila(FILA f)
{
  if (f.inicio == -1) return;
  int atual = f.inicio;
  while (atual >= 0)
  {
    printf("%d ", f.A[atual].ch);
    if (atual == f.fim) break;
    atual = (atual + 1) % MAX;
  }
  printf("\n");
}

void inicializarListaE(FILA * f)
{
  f->fim = -1;
  f->inicio = -1;
}

int tamanhoFila(FILA f)
{
  if (f.inicio == -1 && f.inicio == f.fim) return 0;
  else if (f.fim >= f.inicio) return f.fim - f.inicio + 1;
  return f.fim - f.inicio + MAX + 1;
}

void entrarFilaE(TIPOCHAVE ch, FILA * f)
{
  if (tamanhoFila(*f) == MAX) return;
  if (f->inicio == -1) f->inicio = 0;
  f->fim = (f->fim + 1) % MAX;
  f->A[f->fim].ch = ch;
}

TIPOCHAVE sairFilaE(FILA * f)
{
  // Se a lista estiver vazia
  if (f->inicio == -1) return -1;
  TIPOCHAVE ch = f->A[f->inicio].ch;
  // Se a lista estiver só com um elemento reinicializamos ela
  if (tamanhoFila(*f) == 1) inicializarListaE(f);
  else f->inicio = (f->inicio + 1) % MAX;
  return ch;
}

int main()
{
  FILA jorge;

  TIPOCHAVE chave = 10;

  inicializarListaE (&jorge) ; //inicializa fila estática
  printFila(jorge);
  entrarFilaE(10, &jorge); //inserir novo elemento ao final
  printFila(jorge);
  entrarFilaE(20, &jorge); //inserir novo elemento ao final
  printFila(jorge);
  entrarFilaE(30, &jorge); //inserir novo elemento ao final
  printFila(jorge);
  entrarFilaE(40, &jorge); //inserir novo elemento ao final
  printFila(jorge);
  entrarFilaE(50, &jorge); //inserir novo elemento ao final
  printFila(jorge);

  sairFilaE(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFila(jorge);

  sairFilaE(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFila(jorge);

  sairFilaE(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFila(jorge);

  sairFilaE(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFila(jorge);

  sairFilaE(&jorge); // retirar um item da frente ou retornar -1 se vazia
  printFila(jorge);

  printf("Tamanho: %d\n", tamanhoFila(jorge));

  return 0;
}