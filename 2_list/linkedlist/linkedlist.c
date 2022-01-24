#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *List;

    List = (LinkedList *)malloc(sizeof(LinkedList));
    List->currentElementCount = 0;

    //think headerNode == NULL (으로 초기화 될 수 없음)
    List->headerNode.data = 0;
    List->headerNode.pLink = NULL;
    return (List);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *Nodetemp;

	//count보다 큰 postion위치에 넣으면 안됨
    if (position > pList->currentElementCount || position < 0)
	{
        printf("not !!");
		return (FALSE);
	}

	//Nodetemp 복사 시키기
	Nodetemp = (ListNode *)malloc(sizeof(ListNode));
	Nodetemp->data = element.data;
	Nodetemp->pLink = element.pLink;

	ListNode *move;
	move = &(pList->headerNode);
	//	1. 처음에 넣을 때
	if (position == 0)
	{
		//	원소가 아무것도 없을 때
		if (pList->headerNode.pLink == NULL)
		{
			(pList->currentElementCount)++;
			pList->headerNode.pLink = Nodetemp;
			return (TRUE);
		}
		//	원소가 있는데 넣을 때
		else
		{
			(pList->currentElementCount)++;
			Nodetemp->pLink = move->pLink;
			move->pLink = Nodetemp;
			return (TRUE);
		}
	}
	//	2. 중간에 넣을 때
	else
	{
		int pos = position;
		(pList->currentElementCount)++;

		while (pos > 0)
		{
			move = move->pLink;
			pos--;
		}

		Nodetemp->pLink = move->pLink;
		move->pLink = Nodetemp;

		return (TRUE);
	}
	

	//원소가 처음에 넣을 때

	// 중간에 넣을 때

	// //리스트 내에 원소의 갯수가 0일 때
	// if (pList->currentElementCount == 0)
	// {
	// 	(pList->currentElementCount)++;
	// 	pList->headerNode.data = Nodetemp->data;
	// 	pList->headerNode.pLink = Nodetemp->pLink;
	// //pList->headerNode = Nodetemp;
	// //
	// 	return (TRUE);
	// }
	// // 리스트 내에 원소의 갯수가 1개 이상 일 때
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
