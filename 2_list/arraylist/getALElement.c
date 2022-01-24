
#include "arraylist.h"

ArrayListNode* getALElement(ArrayList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
    {
        printf("not found\n");
        return (NULL);
    }
    // ArrayListNode *temp;

    // int i = 0;
    // while(i < position)
    // {
    //     pList->pElement[i];
    //     ++i;
    // }
    // temp = pList->pElement[i];
    return(&(pList->pElement[position]));
}