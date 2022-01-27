#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
    DoublyListNode *move;

    if (position < 0 || position >= pList->currentElementCount)
    {
        printf("out of range\n");
        return (NULL);
    }
    move = &(pList->headerNode);

    int i = 0;
    while(i < position)
    {
        move = move->pRLink;
        ++i;
    }
    return (move->pRLink);
}