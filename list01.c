//  Lista Encadeada Simples

/*=============================================
    Bibliotecas
=============================================*/

#include <stdio.h>
#include <stdlib.h>

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
    // pointer aponta para cabeça da lista
    Node *pointer = list->head;

    if (pointer == NULL)
        printf("Lista vazia");

    while (pointer)
    {
        printf("%d ", pointer->data.id);
        // pointer vai ser o próximo
        pointer = pointer->next;
    }

    printf("\n");
}

/*=============================================

1-lista criada
2-Função push
3-Mostra lista

===============================================*/