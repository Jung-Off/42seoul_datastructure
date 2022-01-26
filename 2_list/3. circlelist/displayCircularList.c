#include "circlelist.h"

void displayCircularList(CircularList *head)
{
    CircularListNode *Node = head->headerNode;
    CircularListNode *first = head->headerNode;

    if (head->headerNode == 0)
    {
        printf("empty!\n");
        return ;
    }
    printf("[head pointer] -> ");
    while (1)
    {
        printf("[%d] -> ", Node->data);

        Node = Node->pRlink;
        if (Node == first)
        {
            printf("[END] -> ");
            printf("[%d] ", Node->data);
            break;
        }
    }
    printf("\n\n");
}