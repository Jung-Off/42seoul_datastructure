
#include "doublylist.h"

void clearDoublyList(DoublyList* pList)
{
    if (pList->headerNode.pRLink == NULL)
    {
        printf("isempty !\n");
        return ;
    }
    DoublyListNode *move;
    DoublyListNode *temp;
    DoublyListNode *first;

    first = &pList->headerNode;
    move = pList->headerNode.pRLink;

    pList->currentElementCount = 0;
    pList->headerNode.pRLink = NULL;    //
    pList->headerNode.pLLink = NULL;    //
    
    while (move != first)
    {
        temp = move->pRLink;
        free(move);
        move = temp;
    }
}