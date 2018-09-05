#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList 
{
    struct Node *start;    
};

struct LinkedList *create_linked_list()
{
    struct LinkedList *head = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    head->start = NULL;
}

void insert_node(struct LinkedList *head, int el, int index)
{ 
    if (head->start != NULL) {
        struct Node *temp = head->start, *prev = NULL;
        int i = 0;

        while (temp != NULL && i++ < index)
        {
            prev = temp;
            temp = temp->next;
        }     

        if (temp == NULL)
        {
            temp = (struct Node *) malloc(sizeof(struct Node));
            temp->data = el;
            temp->next = NULL;

            prev->next = temp;
        }
        else
        {
            prev->next = (struct Node*) malloc(sizeof(struct Node));
            prev->next->data = el;
            prev->next->next = temp;
        }
    }
    else
    {
        head->start = (struct Node *) malloc(sizeof(struct Node));
        head->start->data = el;
        head->start->next = NULL;
    }
}

void delete_node(struct LinkedList *head, int index)
{
    if (index == 0 && head->start != NULL)
    {
        char *temp = (char*) head->start;
        head->start = head->start->next; 
        free((struct Node*) temp);
        return;
    } 

    struct Node *temp = head->start, *prev = NULL;
    int i = 0;


    while (temp != NULL && i++ < index)
    {
        prev = temp;
        temp = temp->next;
    }     

    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
}

void print_list(struct LinkedList *head)
{
    struct Node *temp = head->start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    struct LinkedList *list = create_linked_list();
    insert_node(list, 1, 0);
    insert_node(list, 2, 1);
    insert_node(list, 4, 2);
    insert_node(list, 3, 3);

    
    print_list(list);

    delete_node(list, 3);
    delete_node(list, 3);
    delete_node(list, 1);
    delete_node(list, 0);

    print_list(list);
}
