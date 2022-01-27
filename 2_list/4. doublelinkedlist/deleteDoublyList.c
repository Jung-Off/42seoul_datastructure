
#include "doublylist.h"

void deleteDoublyList(DoublyList* pList)
{
    printf("delete\n");
    if (pList->headerNode.pRLink != NULL)
        clearDoublyList(pList);
    free(pList);
}