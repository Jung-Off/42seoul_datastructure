
#include "arraylist.h"

void clearArrayList(ArrayList* pList)
{
    pList->currentElementCount = 0;
    free(pList->pElement);
}