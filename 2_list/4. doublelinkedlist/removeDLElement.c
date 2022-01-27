#include "doublylist.h"

int removeDLElement(DoublyList* pList, int position)
{
    DoublyListNode *temp;

     if (position < 0 || position >= pList->currentElementCount)
        return (FALSE);
    
    temp = &(pList->headerNode);

    if (pList->headerNode.pRLink == NULL)
    {
        printf("isempty !\n");
        return (FALSE);
    }
    else
    {
        DoublyListNode *remove = NULL;
        if (position == 0) //0일 때
        {
            if (pList->currentElementCount == 1) //1개일때
            {
                temp = temp->pRLink;
                free(temp);
                pList->headerNode.pLLink = NULL;
                pList->headerNode.pRLink = NULL;
            }
            else 
            {
                remove = temp->pRLink;
                remove->pRLink->pLLink = temp;
                temp->pRLink = remove->pRLink;
                free(remove);
            }
        }
        else //중간 맨뒤
        {
            int i = 0;
            while (i < position)
            {
                temp = temp->pRLink;
                ++i;
            }
            remove = temp->pRLink;
            remove->pRLink->pLLink = temp;
            temp->pRLink = remove->pRLink;
            free(remove);   
        }
    }
    pList->currentElementCount--;
    return (TRUE);
}