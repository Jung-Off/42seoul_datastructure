#include "linkedlist.h"

int removeLLElement(LinkedList* pList, int position)
{
    ListNode *Nodetemp = NULL;
	ListNode *move;
    
    if (position >= pList->currentElementCount || position < 0)
	{
        printf("not delete!!\n");
		return (FALSE);
	}

    move = &(pList->headerNode);
	//	1. 처음에 지울 때
	// if (position == 0)
	// {
		//	원소가 아무것도 없을 때
		if (pList->headerNode.pLink == NULL)
        {
			printf("List is empty");
            return (FALSE);
        }
        // //	원소가 있는데 지울 때 
		// else
		// {
        //     Nodetemp = move->pLink;
        //     move->data = move->pLink->data;
		// 	move->pLink = Nodetemp->pLink;
        //     free(Nodetemp);
		// }
	// }
	//	2. 중간에 지울 때 + 마지막에 지울 때
	else
	{
		int pos = position;
		while (pos > 0)
		{
			move = move->pLink;
			pos--;
		}
        Nodetemp = move->pLink;
        move->pLink = Nodetemp->pLink;
        free(Nodetemp);
	}
	(pList->currentElementCount)--;
	return (TRUE);
}
