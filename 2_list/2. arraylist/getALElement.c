
#include "arraylist.h"

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
    {
        printf("not found\n");
        return (NULL);
    }
    return(&(pList->pElement[position]));
}