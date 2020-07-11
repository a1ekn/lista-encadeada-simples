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

/*=============================================
    Função Main
=============================================*/

int main()
{
    List *list = createList();

    printf("%d", list->size);
}

/*=============================================
    Funções
=============================================*/

List *createList()
{

    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

/*=============================================

1-lista criada

===============================================*/