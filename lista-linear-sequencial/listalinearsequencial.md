# Aula 1:
## Lista Linear Sequencial

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
#### Exemplo no arquivo main.c:

* Tarefinha >> Brincar com a lista

# Aula 2:

## Exericios da ultima aula:
1 . Retornar a chave do primeiro elemento da lista;
## Ex:
```c
int primeiroElemento(LISTA l)
{
  return l.nmrElem > 0 ? l.A[0].chave : -1;
}
```
2 . Retornar a chave do último elemento da lista;
## Ex:
```c
int ultimoElemento(LISTA l)
{
  return l.nmrElem > 0 ? l.A[l.nmrElem].chave : -1;
}
```
3 . Retornar a chave do n-ésimo elemento da lista;
## Ex:
```c
int nesimoElemento(LISTA l, int n)
{
  return l.nmrElem <= n ? l.A[n-1].chave : -1;
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
  return l.nmrElem > 0 ? l.A[0].chave : VALOR_INVALIDO;
}
int ultimoElemento(LISTA l)
{
  return l.nmrElem > 0 ? l.A[l.nmrElem].chave : VALOR_INVALIDO;
}
int nesimoElemento(LISTA l, int n)
{
  return l.nmrElem <= n ? l.A[n-1].chave : VALOR_INVALIDO;
}
```
Dessa forma é mais rapido e fácil atualizarmos o valor inválido caso alguma regra na composição da lista tenha mudado;