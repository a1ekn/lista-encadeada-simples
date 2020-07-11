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

    printf("%d-%d-%d", list->head->data.id, list->head->next->data.id, list->head->next->next->data.id);
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

/*=============================================

1-lista criada
2-Função push

===============================================*/