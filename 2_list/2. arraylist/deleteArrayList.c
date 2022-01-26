
#include "arraylist.h"

void deleteArrayList(ArrayList* pList)
{
    free(pList->pElement);
    free(pList);
}