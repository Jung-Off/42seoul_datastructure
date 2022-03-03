#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack	*stack;

	stack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!stack)
		return (NULL);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	new = (StackNode*) malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	new->data = element.data;
	new->pLink = NULL;
	if (isLinkedStackEmpty(pStack))
		pStack->pTopElement = new;
	else
	{
		new->pLink = pStack->pTopElement;
		pStack->pTopElement = new;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *pop;

	if (isLinkedStackEmpty(pStack))
		return (NULL);
	pop = pStack->pTopElement;
	pStack->pTopElement = pop->pLink;
	pop->pLink = NULL;
	pStack->currentElementCount--;
	return (pop);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*del;
	StackNode	*cur;

	cur = pStack->pTopElement;
	del = NULL;
	while (cur)
	{
		del = cur;
		cur = cur->pLink;
		free(del);
	}
	free(pStack);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

void displayLinkedStack(LinkedStack *pStack)
{
	StackNode *cur;
	
	if (isLinkedStackEmpty(pStack))
		printf("no element");
	else
		printf("stack: ");
	cur = pStack->pTopElement;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->pLink;
	}
	printf("\n");
}
