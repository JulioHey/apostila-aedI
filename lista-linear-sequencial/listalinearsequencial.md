# Lista Linear Sequencial
## Aula 1:

## Sequencial:
- A ordem lógica coincide com a ordem física (memória);
### Ex:
```c
typedf struct {
REGISTRO A[MAX];
int nmrElementosentos;
} LISTA;
```

* nmrElementosentos é o numero de elementos dentra da lista que vai ser manipulado durante atualizações;
* MAX é o tamanho máximo do vetor;

* A seguir temos o exemplo de uma implementação simples de um código em C de uma lista linear sequencial;

### Exemplo no arquivo main.c:

* Tarefinha >> Brincar com a lista

## Aula 2:

## Exericios da ultima aula:
1 . Retornar a chave do primeiro elemento da lista;
## Ex:
```c
int primeiroElemento(LISTA l)
{
  return l.nmrElementos > 0 ? l.A[0].chave : -1;
}
```
2 . Retornar a chave do último elemento da lista;
## Ex:
```c
int ultimoElemento(LISTA l)
{
  return l.nmrElementos > 0 ? l.A[l.nmrElementos].chave : -1;
}
```
3 . Retornar a chave do n-ésimo elemento da lista;
## Ex:
```c
int nesimoElemento(LISTA l, int n)
{
  return l.nmrElementos <= n ? l.A[n-1].chave : -1;
}
```
4. Destruir a lista;
## Ex:
```c
void destruirLista(LISTA * l)
{
  l->nrmElem = 0;
}
```
5 . Nesse caso a melhor saída seria definirmos um valor invalido e usarmos ele em vez do -1, no caso de lista ou n inválido;
## Ex:
```c
/* Aplicando as mudanças */
#define VALOR_INVALIDO -1
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
```
Dessa forma é mais rapido e fácil atualizarmos o valor inválido caso alguma regra na composição da lista tenha mudado;

## Exercicios de agora:
1. Inserção direta em uma posição específica - retorna true se ok, false se não;
```c
/* Protótipo da função */
bool inserirElementoListaSeq(TIPOCHAVE ch, int i, lista * l)
```
Para isso precisamos definir o nome tipo booleano, que não existe em c, podemos fazer isso dessa forma:
### Ex:
```c
typedef int bool;

#define true 1
#define false 0
```
Agora podemos usar o true e false no nosso código...
### Ex de implementação:
```c
bool inserirElementoListaSeq(TIPOCHAVE ch, int i, LISTA * l)
{
  /* Não foi possivel inserir o elemento na posicao i */
  if (i > l->nmrElementos) return false;
  int iterador = i;
  l->nmrElementos += 1;

  TIPOCHAVE aux = l->A[iterador].chave;
  l->A[iterador].chave = ch;
  l->A[iterador+1].chave = aux;
  
  for (iterador = l->nmrElementos - 1; iterador > i + 1; iterador--)
  {
    l->A[iterador].chave = l->A[iterador - 1].chave;
  }
}
```
2 . Busca sequencial
Retorna a posição (índice) que se encontra a chave procurada;
### Ex:
```c
int buscaSequencial(TIPOCHAVE ch, LISTA l)
{
  int iterador;
  for (iterador = 0; iterador < l.nmrElementos; iterador++)
  {
    if (l.A[iterador].chave == ch) return iterador;
  }
  return VALOR_INVALIDO;
}
```
3 . Exclusão de um elemento da lista
Retorna true se a exclusão foi bem sucedida;
```c
/* Protótipo da função */
bool excluirElementoListaSeq(TIPOCHAVE ch, lista * l)
```
### Ex:
```c
bool excluirElementoListaSeq(TIPOCHAVE ch, LISTA * l)
{
  int iterador;
  bool elementoAchado = false;
  for (iterador = 0; iterador < l->nmrElementos; iterador++)
  {
    if (elementoAchado)
    {
      l->A[iterador-1].chave = l->A[iterador].chave;
    }
    if (l->A[iterador].chave == ch && !elementoAchado) 
    {
      elementoAchado = 1;
    }
  }

  l->nmrElementos -= 1;
  return elementoAchado;
}
```

## Busca Ordenada

* No último algoritmo feito em aula:
```c
int buscaSequencial(TIPOCHAVE ch, LISTA l)
{
  int iterador;
  for (iterador = 0; iterador < l.nmrElementos; iterador++)
  {
    if (l.A[iterador].chave == ch) return iterador;
  }
  return VALOR_INVALIDO;
}
```
* A complexidade de tempo é 2n = O(n)
* Seria possível diminuirmos isso??
* Busca com sentinela:
```c
int buscaSent(TIPOCHAVE ch, LISTA l)
{
  int iterador = 0;
  l.A[l.nmrElementos].chave = ch;
  while (l.A[iterador] != ch) i++;
  if (i > l.nmrElementos - 1) return VALOR_INVALIDO;
  return i;
}
```
* No caso de uma lista ordenada podemos melhorar isso:
```c
int buscaSent(TIPOCHAVE ch, LISTA l)
{
  int iterador = 0;
  l.A[l.nmrElementos].chave = ch;
  while (l.A[iterador].chave < ch) iterador++;
  if (iterador > l.nmrElementos - 1 || l.A[iterador].chave != ch) return VALOR_INVALIDO;
  return iterador;
}
```
Dessa forma podemos parar a execução do algoritmo antes de iterar por toda lista, então temos que;
* Melhor caso: 1;
* Caso médio: n/2;
* Pior caso: n + 1;
Ainda mantemos o O(n);

No entanto podemos fazer melhor porque somos FODA, através da BUSCA BINARIA UAU:

## Busca Binaria
* Primeiro escolhemos o número médio na lista, assim sendo se lista tem tamanho n, escolhemos n/2;
* Caso a ch < n/2, escolhemos o novo valor médio da sublista que vai do indice 0 ao n/2, assim sendo n/4;
* Isso até chegarmos a uma lista de tamanho 1;
* Dessa forma podemos mudar a complexidade de tempo para O(log(n));

```c
int buscaBin(TIPOCHAVE ch, LISTA l)
{
  int limiteInferior, limiteSuperior, meio;
  limiteInferior = 0;s
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
```
* Esse algoritmo tem complexidade de lg(n), mas tomando em conta a análise assintótica, temos que O(log(N))
