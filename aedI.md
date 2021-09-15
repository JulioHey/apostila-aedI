### AED-Introdução
- Listas Lineares:
- Sequencial:
- Vetores ou arrays;
- Ligadas (ou Encadeadas):
- Dentro de cada elemento, existe um ponteiro para o próximo elemento;
- Filas;
- Listas Não Lineares;
- Árvores Binárias;
- Árvores Binárias de busca;
- Árvores AVL;

### Notação geral:
Notação geral para qualquer tpo de estrutura, com suas especifidades para cada uma
#### Ex:
```c
  typedef struct {
  TIPOCHAVE chave;
  // Outro campos;
  } REGISTRO;
```

### Sequencial:
- A ordem lógica coincide com a ordem física (memória);
#### Ex:
```c
typedf struct {
REGISTRO A[MAX];
int nmrElementos;
} LISTA;
```

* nmrElementos é o numero de elementos dentra da lista que vai ser manipulado durante atualizações;
* MAX é o tamanho máximo do vetor;

* A seguir temos o exemplo de uma implementação simples de um código em C de uma lista linear sequencial;
#### Ex:
```c
#include <stdio.h>

#define MAX 50

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
```

* Tarefinha >> Brincar com a lista
