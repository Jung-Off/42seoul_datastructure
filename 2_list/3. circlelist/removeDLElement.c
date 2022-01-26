
#include "circlelist.h"

int removeDLElement(CircularList* pList, int position)
{
    if (position < 0 || position >= pList->currentElementCount)
        return (FALSE);
    
    if (pList->headerNode == NULL)
    {
        printf("empty!");
        return (FALSE);
    }
    else
    {
        CircularListNode* move = pList->headerNode;
        CircularListNode* temp = NULL;

        if (position == 0)
        {
            if (pList->currentElementCount == 1)
            {
                pList->headerNode = NULL;
                free(move);
            }   
            else
            {
                temp = move;
                pList->headerNode = move->pRlink;
                
                int i = 0;
                while (i < pList->currentElementCount - 1)
                {
                    move = move->pRlink;
                    ++i;
                }
                move->pRlink = pList->headerNode;
                free(temp);
            }
        }
        else
        {
            //맨마지막거 지울 때 릭!
            int i = 0;
            while (i < position - 1)
            {
                move = move->pRlink;
                ++i;
            }
            temp = move->pRlink;
            move->pRlink = temp->pRlink;
            free(temp);
            // temp = NULL;
        }

        pList->currentElementCount--;
    }
    return (TRUE);
}
