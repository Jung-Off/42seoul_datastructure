
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

        if (position == 0)  //위치가 0
        {
            if (pList->currentElementCount == 1)    //1개 일때
            {
                pList->headerNode = NULL;
                free(move);
            }   
            else    //많을 때
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
        else    //위치가 1이상
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
