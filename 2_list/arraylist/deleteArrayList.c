
#include "arraylist.h"

void deleteArrayList(ArrayList* pList)
{
    clearArrayList(pList);
    free(pList);
}