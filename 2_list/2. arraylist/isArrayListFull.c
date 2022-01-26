
#include "arraylist.h"

int isArrayListFull(ArrayList* pList)
{
    if (pList->currentElementCount == pList->maxElementCount)
        return (1);
    return (0);
}