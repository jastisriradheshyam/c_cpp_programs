#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 * initialize the linked list
 */
void init(NODE **head)
{
    *head = NULL;
}

/**
 * reverse the link list
 */
NODE *reverse(NODE *node)
{
    NODE *temp;
    NODE *previous = NULL;
    while (node != NULL)
    {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

/**
 * add the node to the list
 * @param NODE             last node of the list.
 * @param DATA             data in the node.
 * @return                 next node of the list.
 */
NODE *add(NODE *node, DATA data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        exit(0); // no memory available
    }
    temp->data = data;
    temp->next = node;
    node = temp;
    return node;
}

/**
 * print the linked list
 */
void print_list(NODE *head)
{
    head = reverse(head);
    NODE *temp;
    int indent = 0;
    printf("Print chain\n");
    printf("===========\n");
    for (temp = head; temp; temp = temp->next, indent = indent + 2)
    {
        printf("%*sPrevious hash\t%d\n", indent, "", temp->data.info.previous_block_hash);
        printf("%*sBlock hash\t%d\n", indent, "", temp->data.info.block_hash);
        printf("%*sTransaction\t%s\n", indent, "", temp->data.info.transactions);
        printf("%*s\n", indent, "");
    }
    printf("\r\n");
}

/**
 * Free the linked list out of memory
 */
NODE *free_list(NODE *head)
{
    NODE *tmpPtr = head;
    NODE *followPtr;
    while (tmpPtr != NULL)
    {
        followPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
        free(followPtr);
    }
    return NULL;
}