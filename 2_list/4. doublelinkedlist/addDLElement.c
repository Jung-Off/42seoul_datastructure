#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode *temp;

    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    
    temp = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    
    temp->data = element.data;
    temp->pLLink = &(pList->headerNode);
    temp->pRLink = &(pList->headerNode);
    
    if (pList->headerNode.pRLink == NULL)
    {
        pList->headerNode.pRLink = temp;
        pList->headerNode.pLLink = temp;
    }
    else
    {
        if (position == 0)
        {
            temp->pRLink = pList->headerNode.pRLink;
            pList->headerNode.pRLink = temp;
            temp->pLLink = &pList->headerNode;
            temp->pRLink->pLLink = temp;
        }
        else if (position <= pList->currentElementCount)
        {
            DoublyListNode *add_before = &(pList->headerNode);

            int i = 0;
            while (i < position)
            {
                add_before = add_before->pRLink;
                ++i;
            }
            temp->pRLink = add_before->pRLink;
            add_before->pRLink = temp;
            temp->pRLink->pLLink = temp;
            temp->pLLink = add_before;
        }
    }
    pList->currentElementCount++;
    return (TRUE);
}