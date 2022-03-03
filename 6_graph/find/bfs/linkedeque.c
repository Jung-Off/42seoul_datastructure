#include "linkedeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque* res;

    res = calloc(sizeof(LinkedDeque), 1);
    if (!res)
        return (NULL);
	return (res);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *new;
    
    if (!pDeque)
        return (FALSE);
    new = calloc(sizeof(DequeNode), 1);
    if (!new)
        return (FALSE);
    // *new = element;
    new->data = element.data;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = new;
        pDeque->pRearNode = new;
    }
    else
    {
        new->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = new;
        pDeque->pFrontNode = new;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *new;
	
	if (!pDeque)
		return (FALSE);
	new = calloc(sizeof(DequeNode), 1);
	if (!new)
		return (FALSE);
	new->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = new;
		pDeque->pRearNode = new;
	}
	else
	{
		pDeque->pRearNode->pRLink = new;
		new->pLLink = pDeque->pRearNode;
		pDeque->pRearNode = new;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (!pDeque || isLinkedDequeEmpty(pDeque))
		return (NULL);
	else
	{
		del = pDeque->pFrontNode;
		pDeque->pFrontNode = del->pRLink;
		if (pDeque->currentElementCount == 1)
			pDeque->pRearNode = NULL;
		else
		{
			pDeque->pFrontNode->pLLink = NULL;
			del->pRLink = NULL;
		}
	}
	pDeque->currentElementCount--;
	return (del);
}
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode *del;
    
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    del = pDeque->pRearNode;
    pDeque->pRearNode = del->pLLink;
    if (pDeque->currentElementCount > 1)
    {
        pDeque->pRearNode->pRLink = NULL;
        del->pLLink = NULL;
    }
    else
        pDeque->pFrontNode = NULL;
    pDeque->currentElementCount--;
    return (del);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (!pDeque)
        return (NULL);
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
    DequeNode* curr;
	DequeNode* del;
	
	if (!pDeque || isLinkedDequeEmpty(pDeque))
        return ;
	curr = pDeque->pFrontNode;
	for (int i = 0; i < pDeque->currentElementCount; i++)
	{
		del = curr;
		curr = curr->pRLink;
		free(del);
        del = NULL;
	}
	free(pDeque);
    pDeque = NULL;
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
    return FALSE;
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if(!pDeque)
        return (FALSE);
	return (pDeque->currentElementCount == 0);
}

void displayDeque(LinkedDeque* pDeque)
{
    DequeNode* curr;

    if (!pDeque)
        return ;
    printf(":::Deque Info:::\n");
    printf("current cnt: %d\n", pDeque->currentElementCount);
    if (!isLinkedDequeEmpty(pDeque))
    {
        curr = pDeque->pFrontNode;
        for (int i = 0; i < pDeque->currentElementCount; i++)
        {
            printf("[%d]: %d | ", i, curr->data);
            curr = curr->pRLink;
        }
        printf("\n");
        printf("front data: %d, rear data: %d\n", pDeque->pFrontNode->data, pDeque->pRearNode->data);
    }
}

