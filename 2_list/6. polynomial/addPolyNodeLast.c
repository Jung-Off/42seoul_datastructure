#include "linkedlist.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
    ListNode input_node = {0, 0, 0};

    input_node.coef = coef;
    input_node.degree = degree;

    if (pList == NULL)
        return (FALSE);

    int length = getLinkedListLength(pList);
    addLLElement(pList, length, input_node);

    return (TRUE);
}