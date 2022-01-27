#include "linkedlist.h"

void clearLinkedList(LinkedList* pList) //��� �� ����� List�� �����.
{
    if (pList->headerNode.pLink == NULL)
    {
        printf("isempty !\n");
        return ;
    }

    ListNode *move;
    ListNode *next;

    move = pList->headerNode.pLink;
    pList->headerNode.pLink = NULL;
    pList->currentElementCount = 0;

    while (move)
    {
        next = move->pLink;
        free(move);
        move = next;
    }
}