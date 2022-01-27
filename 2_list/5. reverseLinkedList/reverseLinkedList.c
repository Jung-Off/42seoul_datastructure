
#include "linkedlist.h"

void reverseLinkedList(LinkedList *pList)
{
    if (pList->headerNode.pLink == NULL)
    {
        printf("empty !");
        return ;
    }
    if (pList->currentElementCount == 1)
        return ;
    printf("reverse!\n");

    ListNode *prev;
    ListNode *curr;
    ListNode *next;

    prev = 0;
    next = 0;
    curr = pList->headerNode.pLink;

    while (curr)
    {
        next = curr->pLink;

        if (prev == NULL)
            curr->pLink = NULL;
        else
            curr->pLink = prev;
        
        prev = curr;
        curr = next;
    }
}

