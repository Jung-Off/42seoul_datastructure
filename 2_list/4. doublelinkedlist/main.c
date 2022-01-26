
#include <stdio.h>
#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList *new;

    new = (DoublyList *)malloc(sizeof(DoublyList));
    
    new->currentElementCount = 0;
    new->headerNode.data = 0;
    new->headerNode.pLLink = 0;
    new->headerNode.pRLink = 0;
    return new;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode *temp;

    
    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    
    temp = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    *temp = element;
    

    if (pList->headerNode.pRLink == NULL)
    {
        pList->head
    }
    else
    {
        
    }
    




}

int main()
{
    DoublyList *temp;

    temp = createDoublyList();


}