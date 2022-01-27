#include "linkedlist.h"

void deleteLinkedList(LinkedList* pList)
{
    printf("delete\n");
    if (pList->headerNode.pLink != NULL)
        clearLinkedList(pList);
    free(pList);
}
