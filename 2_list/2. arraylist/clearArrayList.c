
#include "arraylist.h"

void clearArrayList(ArrayList* pList)
{
    if (pList->pElement == NULL)
    {
        printf("isempty !\n");
        return ;
    }
    int i = 0;

    while (i < pList->currentElementCount)
    {
        pList->pElement[i].data = 0;
        ++i;
    }
    // memset(pList->pElement, 0, sizeof(ArrayListNode) * pList->maxElementCount);
    pList->currentElementCount = 0;
}