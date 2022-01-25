#include "linkedlist.h"

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *Nodetemp;
	ListNode *move;

	//count���� ū postion��ġ�� ������ �ȵ�
    if (position > pList->currentElementCount || position < 0)
	{
        printf("not add!!\n");
		return (FALSE);
	}

	//Nodetemp ���� ��Ű��
	Nodetemp = (ListNode *)malloc(sizeof(ListNode));
	Nodetemp->data = element.data;
	Nodetemp->pLink = element.pLink;

	move = &(pList->headerNode);

	// �پ��ִ°� ���� ��
	if (pList->headerNode.pLink == NULL)
		pList->headerNode.pLink = Nodetemp;
	// �پ��ִ°� ���� ��
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
