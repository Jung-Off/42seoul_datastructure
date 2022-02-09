#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*new;

	new = malloc(sizeof(LinkedDeque));
	if (!new)
		return (NULL);
	new->currentElementCount = 0;
	new->pFrontNode = NULL;
	new->pRearNode = NULL;
	return (new);
}


int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode *add = malloc(sizeof(DequeNode));
    
	if (!add)
		return (FALSE);
	*add = element;
	if (pDeque->pFrontNode == NULL)
	{
		pDeque->pFrontNode = add;
		pDeque->pRearNode = add;
	}
	else
	{
		add->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = add;
		pDeque->pFrontNode = add;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode* add = malloc(sizeof(DequeNode));

	if (!add)
		return (FALSE);
    *add = element;
    if (pDeque->pRearNode == NULL)
    {   
        pDeque->pFrontNode = add;
        pDeque->pRearNode = add;
    }
    else
    {
        add->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = add;
        pDeque->pRearNode = add;      
    }
    pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode* del;

    if (pDeque->currentElementCount <= 0)
        return (NULL);
    if (pDeque->currentElementCount == 1)
    {
        del = pDeque->pFrontNode;
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL;
    }
    else
    {
        del = pDeque->pFrontNode;
        del->pRLink->pLLink = NULL;
        pDeque->pFrontNode = del->pRLink;
        del->pRLink = NULL;
    }
    return (del);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode *del;
	
	if (pDeque->currentElementCount <= 0)
		return (NULL);
	if (pDeque->currentElementCount == 1)
	{
		del = pDeque->pFrontNode;
		pDeque->pFrontNode = NULL;
		pDeque->pRearNode = NULL;
	}
	else
	{
		del = pDeque->pRearNode;
		del->pLLink->pRLink = NULL;
		pDeque->pRearNode = del->pLLink;
		del->pLLink = NULL;
	}
	return (del);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode *cur;
	DequeNode *del;

	cur = pDeque->pFrontNode;
	while (cur)
	{
		del = cur;
		free(del);
		cur = cur->pRLink;
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	return (pDeque->currentElementCount == 0);
}

void	displayDeque(LinkedDeque* pDeque)
{
    DequeNode *cur;

    printf("displayDeque\n\n");
    cur = pDeque->pFrontNode;
    while(cur)
    {
        printf("[ %c ] -> ", cur->data);
        cur = cur->pRLink;
    }
    printf("[ NULL ] \n");
}

void	reversedisplay(LinkedDeque* pDeque)
{
	DequeNode *cur;
	
    printf("reversedisplay\n\n");
    
	cur = pDeque->pRearNode;
	while (cur)
	{
		printf("[ %c ] -> ", cur->data);
		cur = cur->pLLink;
	}
    printf("[ NULL ] \n");
}