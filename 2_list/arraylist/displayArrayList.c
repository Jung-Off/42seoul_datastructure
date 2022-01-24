
#include "arraylist.h"

void displayArrayList(ArrayList* pList)
{
     int i = 0;

    while (i < pList->currentElementCount)
    {
        printf("[%d] ", pList->pElement[i].data);
        ++i;
    }
    printf("\n");
}