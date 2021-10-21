# Lista Linear Encadeada:

## Com Alocação Estática:
* __Problema__: Surgiram para suprir um dos maiores inconvenientes das listas lineares sequenciais:
  * Dificuldade da inserção e remoção de elementos em posição específica, exige O(n);
* __Solução__: Posição lógica não precisar coincidir com posição física;

* __Ex__:
  * Lista Linear Encadeada:
    
    * Lógica:

        <span> | <span> | <span> | <span> | <span> | <span> | <span> | <span>
        --- | --- | --- | --- | --- | --- |--- | --- |
        __3__ | __prox__ | => | 8 | prox | => 15 | prox | NULL 

    * Na memória:

      * __Inicio__: 2

        Memória | info | prox
        --- | --- | ---
        0 | 8 | 6
        1 |   | 
        __2__|__3__|__0__
        3 |   | 
        4 |   | 
        5 |   | 
        6 | 15| -1 
        7 |   | 
        8 |   | 

      * Para sabermos quais partes estão vazia utilizaremos uma nova variável chamada dispo, que nesse caso é dispo = 1;
* Em código:
```c
typedef struct {
  TIPOCHAVE chave;
  /* Representa o indice do proximo elemento */
  int prox;
} REGISTRO;
```
```c
typedef struct {
  REGISTRO A[MAX];
  /* Representa o indice do primeiro elemento */
  int inicio;
  /* Representa o indice do proximo elemento disponível */
  int dispo
} LISTA;
```

* Em uma lista completamente cheia, o índice guardado na variavel __dispo__ é __INVÁLIDO__, geralmente -1;
* Em uma lista completamente vazia, o índice guardado na variavel __inicio__ é __INVÁLIDO__, geralmente -1;

```c
void inicializarListaLigada(
  LISTA * lista
)
{
  /* Setamos o primeiro disponivel para o primeiro valor da lista */
  lista->dispo = 0;
  /* Vazia logo não tem início */
  lista->inicio = VALORINVALIDO;

  /* Aqui preenchemos todos valores da lista como prox, em sequencia */
  int iterador;
  for (iterador = 0; iterador < MAX -1; iterador++)
  {
    lista->A[iterador].prox = iterador + 1;
  }
  /* Definimos o final da lista */
  lista->A[MAX - 1].prox = VALORINVALIDO;
}
```

```c
void exibirLista(LISTA lista)
{
  /* Inicializo a lista do inicio */
  int i = lista.inicio;
  /* Printo tudo até achar o final */
  while (i > - 1)
  {
    printf("%d ", lista.A[i].chave);
    i = lista.A[i].prox;
  }
}
```

## Com Alocação Dinâmica:
```c
/* Utilizamos o estrutura para utilizarmos um ponteiro para a estrutura dentro da própria estrutura */
typedef struct estrutura {
  TIPOCHAVE chave;
  /* outros campos... */
  struct estrutura * prox;
} NO;
```
```c
typedef struct {
  NO * inicio;
} LISTA;
```
* Nesse caso não precisamos gerenciar isso com um vetor, pois o NO já aponta para o próximo elemento da lista;

* Métodos atualizados:

```c
void 
```
