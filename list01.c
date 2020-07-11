//  Lista Encadeada Simples

/*=============================================
    Bibliotecas
=============================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*=============================================
    Declaração de Variáveis Globais
=============================================*/

typedef struct dataNode
{
    int id;
} Datanode;

typedef struct node
{
    Datanode data;
    struct node *next;
} Node;

typedef struct list
{
    int size;
    Node *head;
} List;

/*=============================================
    Protótipos de Funções
=============================================*/

List *createList();
void push(List *list, Datanode data);
void printList(List *list);
void pop(List *list);
bool isEmpty(List *list);

/*=============================================
    Função Main
=============================================*/

int main()
{
    List *list = createList();

    Datanode data;

    data.id = 4;
    push(list, data);

    data.id = 8;
    push(list, data);

    data.id = 9;
    push(list, data);

    data.id = 1;
    push(list, data);

    data.id = 2;
    push(list, data);

    data.id = 7;
    push(list, data);

    printList(list);

    pop(list);
    printList(list);
}

/*=============================================
    Funções
=============================================*/
// cria lista vazia
List *createList()
{

    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

// push
void push(List *list, Datanode data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    //grava argumento passado
    node->data = data;
    //ligar nó na cabeça da lista
    node->next = list->head;
    // cabeça da lista igual ao nó criado
    list->head = node;
    list->size++;
}

// mostra lista
void printList(List *list)
{
    // Testa se lista está vazia e se sim não executa o que está abaixo
    if (isEmpty(list))
    {
        printf("Lista vazia");
        return;
    }

    // pointer aponta para cabeça da lista
    Node *pointer = list->head;

    while (pointer)
    {
        printf("%d ", pointer->data.id);
        // pointer vai ser o próximo
        pointer = pointer->next;
    }

    printf("\n");
}

// confere se a lista está vazia
bool isEmpty(List *list)
{
    // faz comparação se size TRUE ou FALSE
    return (list->size == 0);
}

// pop
void pop(List *list)
{
    if (!isEmpty(list))
    {
        // ponteiro auxiliar pointer aponta para onde o head estava apontando (substituindo apontamento)
        Node *pointer = list->head;
        // trocar a head da lista para o next do pointer
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

/*=============================================

1-lista criada
2-Função push
3-Mostra lista
4-Função pop & isEmpty

===============================================*/