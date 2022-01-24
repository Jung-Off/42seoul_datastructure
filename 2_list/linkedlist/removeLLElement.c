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
	//	1. ó���� ���� ��
	// if (position == 0)
	// {
		//	���Ұ� �ƹ��͵� ���� ��
		if (pList->headerNode.pLink == NULL)
        {
			printf("List is empty");
            return (FALSE);
        }
        // //	���Ұ� �ִµ� ���� �� 
		// else
		// {
        //     Nodetemp = move->pLink;
        //     move->data = move->pLink->data;
		// 	move->pLink = Nodetemp->pLink;
        //     free(Nodetemp);
		// }
	// }
	//	2. �߰��� ���� �� + �������� ���� ��
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
