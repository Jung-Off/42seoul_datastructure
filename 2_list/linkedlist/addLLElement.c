#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *Nodetemp;
	ListNode *move;

	//count보다 큰 postion위치에 넣으면 안됨
    if (position > pList->currentElementCount || position < 0)
	{
        printf("not add!!\n");
		return (FALSE);
	}

	//Nodetemp 복사 시키기
	Nodetemp = (ListNode *)malloc(sizeof(ListNode));
	Nodetemp->data = element.data;
	Nodetemp->pLink = element.pLink;

	move = &(pList->headerNode);

	// 붙어있는게 없을 때
	if (pList->headerNode.pLink == NULL)
		pList->headerNode.pLink = Nodetemp;
	// 붙어있는게 있을 때
	else
	{
		int pos = position;
		while (pos > 0)
		{
			move = move->pLink;
			pos--;
		}
		Nodetemp->pLink = move->pLink;
		move->pLink = Nodetemp;
	}
	(pList->currentElementCount)++;
	return (TRUE);
}
