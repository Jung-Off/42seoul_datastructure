
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList* new;

    new = (ArrayList *)malloc(sizeof(ArrayList));

    new->maxElementCount = maxElementCount;
    new->currentElementCount = 0;
    new->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    return (new);
}