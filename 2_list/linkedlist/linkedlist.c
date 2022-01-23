#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *List;

    List = (LinkedList *)malloc(sizeof(LinkedList));
    List->currentElementCount = 0;

    //think headerNode == NULL (���� �ʱ�ȭ �� �� ����)
    List->headerNode.data = 0;
    List->headerNode.pLink = NULL;
    return (List);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *Nodetemp;

	//count���� ū postion��ġ�� ������ �ȵ�
    if (position > pList->currentElementCount || position < 0)
	{
        printf("not !!");
		return (FALSE);
	}

	//Nodetemp ���� ��Ű��
	Nodetemp = (ListNode *)malloc(sizeof(ListNode));
	Nodetemp->data = element.data;
	Nodetemp->pLink = element.pLink;

	//���Ұ� �ƹ��͵� ���� ��

	if (pList->currentElementCount == 0)
	{
		(pList->currentElementCount)++;
		pList->headerNode.data = Nodetemp->data;
		pList->headerNode.pLink = Nodetemp->pLink;
		return (TRUE);
	}
	else
	{
		if (position == 0)
		{
			ListNode *temp;

			//��ó���� 2��°�� ����� ���� ����
			temp->data = pList->headerNode.data;
			temp->pLink = pList->headerNode.pLink;
			//��ó���� �־��ֱ�
			pList->headerNode.data = Nodetemp->data;
			pList->headerNode.pLink = temp->pLink;
			(pList->currentElementCount)++;
		}
		else
		{
			int pos = position;
			printf("hello\n");
			ListNode *move = &(pList->headerNode);
			while (--pos)
			{	
				move = move->pLink;
			}
			
			if (pos != 0)
			{
				Nodetemp->pLink = move->pLink;
				move->pLink = Nodetemp;
			}
			else
			{
				printf("hello2\n");
				move->pLink = Nodetemp->pLink;	
			}
			(pList->currentElementCount)++;

		}
		




	}

	//���Ұ� ó���� ���� ��

	// �߰��� ���� ��

	// //����Ʈ ���� ������ ������ 0�� ��
	// if (pList->currentElementCount == 0)
	// {
	// 	(pList->currentElementCount)++;
	// 	pList->headerNode.data = Nodetemp->data;
	// 	pList->headerNode.pLink = Nodetemp->pLink;
	// //pList->headerNode = Nodetemp;
	// //
	// 	return (TRUE);
	// }
	// // ����Ʈ ���� ������ ������ 1�� �̻� �� ��
	// else
	// {
	// 	ListNode *Movetemp = &(pList->headerNode);
		
	// 	int pos = position;
	// 	// while (--pos > 0)
	// 	// 	Movetemp = Movetemp->pLink;

	// 	if (position == 0)
	// 	{
	// 		Nodetemp->pLink = Movetemp;
	// 		pList->headerNode.data = Nodetemp->data;
	// 		pList->headerNode.pLink = Nodetemp->pLink;
	// 	}
	// 	else
	// 	{
	// 		printf("fdafasdfsda\n");
	// 		Nodetemp->pLink = Movetemp->pLink;
	// 		printf("fdafasdfsda\n");
	// 		Movetemp->pLink->data = Nodetemp->data;
	// 		printf("fdafasdfsda\n");
	// 		Movetemp->pLink->pLink = Nodetemp->pLink;
	// 	}
	// 	(pList->currentElementCount)++;
	// }
	return (TRUE);
}
