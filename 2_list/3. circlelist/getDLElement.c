#include "circlelist.h"

CircularListNode* getDLElement(CircularList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
    {
        printf("not found\n");
        return (NULL);
    }

    CircularListNode *move = pList->headerNode;

    int pos = position;
    while (pos > 0)
    {
        move = move->pRlink;
        --pos;
    }
    return (move);
}