## Listas Lineares Encadeadas Dinâmica:
  * As
### Com Sentinela:
  * Porque utilizar sentinela:
    * Durante a operação de busca fazemos duas operações, um loop e uma comparação;
    * Utilizando sentinelas conseguimos simplificar o código:
  * A __Sentinela__ __NÃO__ faz parte da lista, é um valor a mais para ajudar;
### Circular:
  * O último NO, tera como campo *prox*:
    * O *NO __cabeça__*, o qual tem como *prox*: o primeiro *NO* com valor;
  * Serve como sentinela e como reiniciador de lista:
  ```c
  typedef struct estrutura {
    TIPOCHAVE chave;
    struct estrutura *prox;
  } NO;

  typedef struct {
    NO * cabeça;
  } LISTA;
  ```
  * buscaSeqOrd():
  ```c
  NO * buscaSeqOrd(TIPOCHAVE ch, LISTA l, NO * *ant)
    {
      NO * atual = l.cabeca->prox;
      * ant = l.cabeça;
      lista.cabeca->chave = ch;
      while (atual->chave < ch)
      {
        * ant = atual;
        atual = atual->prox;
      }
      if (atual != l.cabeca && atual->chave == ch) return atual;
      return NULL;
    }
  ```
  INSEREÇÃO:
  ```c
  int insercaoSeqOrd(TIPOCHAVE ch, LISTA * l)
  {
    NO * ant;
    NO * jaTem = buscaSeqOrd(ch, *l, &ant);
    if (jaTem) return 0;
    NO * novoNo = malloc(sizeof(NO));
    novoNo->chave = ch;
    novoNo->prox = ant->prox;
    ant->prox = novoNo;
    return 1;
  }
  ```
  REMOçAO
  ```c
  int remSeqOrd(TIPOCHAVE ch, LISTA * l)
  {
    NO * ant;
    NO * noASerRemovdo = buscaSeqOrd(ch, *l, &ant);
    if (noASerRemovido)
    {
      ant->prox = noASerRemovido->prox;
      free(noASerRemovido);
      return 1;
    }
    return 0;
  }
  ```
  DESTRUIR LISTA
  ```c
  void destruirLista(LISTA * l)
  {
    NO * atual = l->cabeca->prox;
    NO * aux = NULL;
    while (atual != l->cabeca)
    {
      aux = atual;
      atual = atual->prox;
      free(aux);
    }
    l->cabeca->prox = l->cabeca;
  }
  ```