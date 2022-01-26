#include "linkedlist.h"

void clearLinkedList(LinkedList* pList) //노드 다 지우기 List만 남긴다.
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