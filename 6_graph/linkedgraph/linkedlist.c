#include "linkedlist.h"

LinkedList* createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.data = 0;
	list->headerNode.weight = 0;
	list->headerNode.pLink = NULL;
	return (list);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	int idx;
	ListNode *cur;

	if (position < 0 || position > pList->currentElementCount - 1)
		return (NULL);
	idx = 0;
	cur = pList->headerNode.pLink;
	while (idx < position)
	{
		cur = cur->pLink;
		idx++;
	}
	return (cur);
}

int getLinkedListLength(LinkedList* pList)
{
	return (pList->currentElementCount);
}


int addLLElement(LinkedList* pList, int position, ListNode element)
{
	int idx;
	ListNode *cur;
	ListNode *new;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = (ListNode *)malloc(sizeof(ListNode));
	// new->data = element.data;
	// new->weight = element.weight;
	*new = element;
	new->pLink = NULL;
	if (pList->currentElementCount == 0)
		pList->headerNode.pLink = new;
	else
	{
		idx = 0;
		cur = pList->headerNode.pLink;
		if (position == 0)
		{
			new->pLink = pList->headerNode.pLink;
			pList->headerNode.pLink = new;
		}
		else
		{
			while (idx < position - 1)
			{
				idx++;
				cur = cur->pLink;
			}
			if (position !=  pList->currentElementCount)
				new->pLink = cur->pLink;
			cur->pLink = new;
		}
	}
	pList->currentElementCount++;
	return (TRUE);
}

void clearLinkedList(LinkedList* pList)
{
	int idx;
	int count;

	idx = 0;
	count = pList->currentElementCount;
	while (idx < count)
	{
		removeLLElement(pList, 0);
		idx++;
	}
}

void deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		return ;
	clearLinkedList(pList);
	free(pList);
}

int removeLLElement(LinkedList* pList, int position)
{
	int idx;
	ListNode *cur;
	ListNode *remove;

	if (pList->currentElementCount == 0)
		return (FALSE);
	if ((position < 0) || (position > pList->currentElementCount - 1))
		return (FALSE);
	if (pList->currentElementCount == 1)
		free(pList->headerNode.pLink); // NULL추가
	else
	{
		idx = 0;
		cur = pList->headerNode.pLink;
		if (position == 0)
		{
			remove = pList->headerNode.pLink;
			pList->headerNode.pLink = remove->pLink;
			remove->pLink = NULL;
			free(remove); // NULL추가
		}
		else
		{
			while (idx < position - 1)
			{
				cur = cur->pLink;
				idx++;
			}
			remove = cur->pLink;
			if (position == pList->currentElementCount - 1)
				cur->pLink = NULL;
			else
				cur->pLink = remove->pLink;
			free(remove); // NULL추가
		}
	}
	pList->currentElementCount--;
	return (TRUE);
}

// void displayLinkedList(LinkedList* pList)
// {
// 	int idx;
// 	ListNode *get;

// 	idx = 0;
// 	if (pList->currentElementCount == 0)
// 		printf("No element");
// 	else
// 		printf("list: ");
// 	while (idx < pList->currentElementCount)
// 	{
// 		get = getLLElement(pList, idx);
// 		printf("%d ", get->data);
// 		idx++;
// 	}
// 	printf("\n");
// }

void displayLinkedList(LinkedList* pList)
{
	int idx;
	ListNode *get;

	idx = 0;
	if (pList->currentElementCount == 0)
		printf("No connected vertex");
	while (idx < pList->currentElementCount)
	{
		get = getLLElement(pList, idx);
		printf("%d ", get->data);
		idx++;
	}
	printf("\n");
}
