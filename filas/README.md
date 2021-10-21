## Filas
  * Recebemos a informação e a atualizamos ela de acordo com a ordem de chegada;
  * "Quem chega por último fica em último";
  * É uma lista linear em que a inserção e a remoção de elementos segue uma política chamada __FIFO (First In, First Out)__, ou seja, o primeiro que entrou será o primeiro a sair...;
  * Implementação Dinâmica vs Implementação Estática;
### Implementação Dinâmica:
  * Definição de tipos;
  ```c
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
  ```

  * Inicialização da Fila:
  ```c
    void inicializarListaD(FILA * f)
    {
      f->fim = NULL;
      f->inicio = NULL;
    }
  ```

  * Entrar na Fila:
  ```c
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
  ```
  
  * Sair da Fila:
  ```c
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
  ```

### Implementação Estática:
  * Definição de tipos;
  ```c
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
  ```

  * Inicialização da Fila:
  ```c
    void inicializarListaE(FILA * f)
    {
      f->fim = -1;
      f->inicio = -1;
    }
  ```

  * Entrar na Fila:
  ```c
    void entrarFilaE(TIPOCHAVE ch, FILA * f)
    {
      if (tamanhoFila(*f) == MAX) return;
      if (f->inicio == -1) f->inicio = 0;
      f->fim = (f->fim + 1) % MAX;
      f->A[f->fim].ch = ch;
    }
  ```
  
  * Sair da Fila:
  ```c
    TIPOCHAVE sairFilaE(FILA * f)
    {
      if (f->inicio == -1) return -1;
      TIPOCHAVE ch = f->A[f->inicio].ch;
      if (tamanhoFila(*f) == 1) inicializarListaE(f);
      else f->inicio = (f->inicio + 1) % MAX;
      return ch;
    }
  ```
  