#include "circlelist.h"

void deleteCircularList(CircularList* pList)
{
    printf("delete\n");
    if (pList->headerNode != 0)
        clearCircularList(pList);
    free(pList);
}