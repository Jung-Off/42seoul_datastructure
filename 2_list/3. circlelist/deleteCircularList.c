#include "circlelist.h"

void deleteCircularList(CircularList* pList)
{
    if (pList->headerNode == 0)
    {
        printf("empty!\n");
        return ;
    }
    clearCircularList(pList);
    free(pList);
}