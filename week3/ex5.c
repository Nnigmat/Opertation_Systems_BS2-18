#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define NODE_ALLOC ((struct Node *) malloc(sizeof(struct Node)))

struct Node
{
    int el;
    struct Node *next, *prev;
};

struct Node* create_double_linked_list()
{
    struct Node* head = NODE_ALLOC;
    head->next = NULL;
    head->prev = NULL;
    head->el = INT_MAX;
    return head;
}

void insert_node(struct Node* list, int el, int index)
{
    if (list->next == NULL)
    {
        list->next = NODE_ALLOC;
        list->next->prev = list;
        list->next->el = el;
        return;
    } 

    struct Node *cur = list->next, *prev;
    int i = 0;

    while (cur != NULL && i++ < index)
    {
        prev = cur;
        cur = cur->next; 
    }

    if (cur == NULL && i != index)
    {
        prev->next = NODE_ALLOC;
        prev->next->prev = cur;
        prev->next->el = el;
    }
    else 
    {
        prev->next = NODE_ALLOC;
        prev->next->el = el;
        prev->next->prev = prev;
        prev->next->next = cur;
    }
}

void delete_node(struct Node* list, int index)
{
    if (list->next == NULL)
    {
        return;
    }

    struct Node *temp = list->next, *prev;
    int i = 0;

    while (temp != NULL && i++ < index)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (i-1 == index)
    {
        if (temp != NULL && temp->next != NULL)
        {
            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
        }
        else
        {
            prev->next = NULL;
            free(temp);
        }
    } 
}

void print_list(struct Node* list)
{
    struct Node *temp = list->next;
    while (temp != NULL)
    {
        printf("%d ", temp->el);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    struct Node * list = create_double_linked_list();
    insert_node(list, 1, 0);
    insert_node(list, 2, 1);
    insert_node(list, 4, 2);
    insert_node(list, 3, 3);

    print_list(list);

    delete_node(list, 3);
    delete_node(list, 2);
    delete_node(list, 1);

    print_list(list);
}
