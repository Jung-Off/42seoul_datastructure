#include "linkedlist.h"

void clearLinkedList(LinkedList* pList) //��� �� ����� List�� �����.
{
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