## Alocação Dinâmica x Alocação Estática;

    # Dinâmica:
        - Deve ser declarada como um ponteiro do tipo T;
            - Ex:
                int * senhas;
                senhas = malloc(sizeof(int) * NUM_SENHAS);
                ...
                "Preenche o vetor"
                free(senhas);

        - Deve ser usada com malloc() para allocar memória;
        - E ao final usar o free() para liberar memória;
    # Estática:
        - Ao se declarar você tem 2 opções;
        - Declara o tamanho:
            - Ex:
                int senhas[NUM_SENHAS];
                ...
                "Preenche o vetor"
        - Não decalra o tamanho, mas os valores;
            - Ex:
                int senhas[] = {senha1, ..., senhaN};
        - Declara ambos;
            - Ex:
                int senhas[NUM_SENHAS] = {senha1, ..., senhaN};
            - O número de elementos deve ser exatamente igual ao tamanho na declaração;
        - Não é necessário usar free ao se declarar estaticamente;


    Ao liberar espaço de memória tanto estaticamente quanto dinamicamente, você não altera o valor naquele espaço, mas libera esse espaço para mudanças;

    DICA:
        - free():
            Ao se usar free é melhor fazer desse jeito;
            if (P != NULL)
            {
                free(P);
                P = NULL;
            }
            Dessa forma você apenas vai liberar a memória caso haja algo guardado;
        - malloc():
            Mesma coisa no malloc:
            if (senha = malloc(TAM))
            {
                PRINTAR ERRO FOI RETORNADO NULL => ERRO NO MALLOC;
            }
            Dessa forma tu não vai fazer o malloc caso retorne erro;
    
    C não tem o chamado de garbage collector, que é capacidade de sair pegando e liberando a memória de tudo que não está sendo utilizado ao final do programa por isso a importância do free();


AED 1:
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


    - Notação geral:
        - Ex:
            typedef struct {
                TIPOCHAVE chave;
                // Outro campos;
            } REGISTRO;

            Aqui utilizamos uma notação geral, para todos tipos de lista;
        - Sequencial:
            - A ordem lógica coincide com a ordem física (memória);
            Ex:
            typedf struct {
                REGISTRO A[MAX];
                int nmrElementos;
            } LISTA;

            nmrElementos é o numero de elementos dentra da lista que vai ser manipulado durante atualizações;
            MAX é o tamanho máximo do vetor;

        Código:
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

    Tarefinha >> Brincar com a lista
