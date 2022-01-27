
#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList *new;

    new = (DoublyList *)malloc(sizeof(DoublyList));
    
    new->currentElementCount = 0;
    new->headerNode.data = 0;
    new->headerNode.pLLink = 0; //
    new->headerNode.pRLink = 0; //
    return new;
}