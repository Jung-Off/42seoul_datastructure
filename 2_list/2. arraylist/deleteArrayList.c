
#include "arraylist.h"

void deleteArrayList(ArrayList* pList)
{
    printf("delete\n");
    if (pList->pElement != NULL)
        free(pList->pElement);
    free(pList);
}