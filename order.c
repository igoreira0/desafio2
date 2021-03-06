#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inc/order.h"

struct node ** findSmallest(struct node ** head)
{
    struct node ** ptrMenor = head;
    
    if(!head || !(*head)) return NULL;
    
    while (*head)
    {
        if((*head)->data < (*ptrMenor)->data)
        {
            ptrMenor = head;
        }
        head = &((*head)->next);
    }
    
    return ptrMenor;
}


void orderListAsc(struct node ** head)
{
    struct node *ordered = NULL, **last = &ordered, **smallest;

    while((smallest = findSmallest(head)) != NULL)
    {
        if((smallest) && (*smallest))
        {
            *last = *smallest;
            *smallest = (*smallest)->next;
            last = &((*last)->next);
        }
    };
    *head = ordered;
}

int put(struct node* *head, int input)
{
    struct node *var;
    var = NULL;
    if (*head == NULL)
    {
        var = (struct node *) malloc(sizeof (struct node));
        if (var == NULL) return (EXIT_FAILURE);
        var->data = input;
        var->next = NULL;
        *head = var;

    }
    else
    {
        var = *head;
        while ((var->next != NULL))
        {
            var = var->next;

        }
        var->next = (struct node *) malloc(sizeof (struct node));
        if (var->next == NULL) return (EXIT_FAILURE);
        var->next->data = input;
        var->next->next = NULL;
    }
    return (EXIT_SUCCESS);
}

void list(struct node* *head)
{
    int cont = 0;
    struct node * item = NULL;

    if(head) item = *head;
    
    printf("-------------------- PRINT LIST --------------------\n\n");
    while (item)
    {
        printf("+-----------------------------------+\n");
        printf("|#%-4d @ %-27p|\n", ++cont, item);
        printf("+-Data-----------+-Next-------------+\n");
        printf("|%16d|%18p|\n", item->data, item->next);
        printf("+----------------+------------------+\n\n");
        item = item->next;
    }
    if(!cont) printf("Lista vazia.\n\n");
    printf("--------------------- END LIST ---------------------\n\n");
    fflush(stdout);
}


int getNumber(char *str){
    
    char* aux;
    aux = strchr(str, ' ');
    return atoi(++aux);
}