#include "circlelist.h"

int addDLElement(CircularList* pList, int position, CircularListNode element)
{
    CircularListNode *temp;
    CircularListNode *move;
	int i;

    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    
    temp = (CircularListNode *)malloc(sizeof(CircularListNode));
    temp->data = element.data;
    temp->pRlink = temp;

	// 아무것도 없을 때
    if (pList->headerNode == NULL)
        pList->headerNode = temp;
    // 뒤에 있을 때
	else
    {
        move = pList->headerNode;
        //맨처음에 넣을 때
		if (position == 0)
        {
            temp->pRlink = move;
            pList->headerNode = temp;

            i = 0;
            while (i < pList->currentElementCount - 1)
            {
                ++i;
                move = move->pRlink;
            }
            move->pRlink = temp;
        }
		// 중간 맨뒤!
        else if (position <= pList->currentElementCount)
        {
            i = 0;
            while (i < position - 1)
            {
                move = move->pRlink;
                ++i;
            }
            temp->pRlink = move->pRlink;
            move->pRlink = temp;
        }

    }
    pList->currentElementCount++;

    return (TRUE);
}