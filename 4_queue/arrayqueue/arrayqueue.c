#include "arrayqueue.h"


ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue	*new;

	new = malloc(sizeof(ArrayQueue));
	if (!new)
		return (NULL);
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	new->front = 0;
	new->rear = 0;
	new->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!(new->pElement))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	// maxElementCount 이상 x
    if (pQueue == NULL)
    {
        printf(" pQueue is (NULL)\n");
        return (FALSE);
    }
	if ((pQueue->rear + 1) % pQueue->maxElementCount == pQueue->front)
    {
        printf(" pQueue is Max ! !\n");
        return (FALSE);
    }
	(pQueue->rear) = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
	// rear = (rear + 1)%maxElementCount
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf(" pQueue is (NULL)\n");
        return (FALSE);
    }
	// curr <= 0
    if (pQueue->currentElementCount == 0)
		return (NULL);
    ArrayQueueNode *delNode = malloc(sizeof(ArrayQueueNode));
	if (!delNode)
		return (NULL);
	delNode->data = pQueue->pElement[pQueue->front + 1].data;
    pQueue->pElement[pQueue->front + 1].data = '\0';
	(pQueue->front) = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (delNode);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	return (&(pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]));
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
    pQueue->pElement = NULL;
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount - 1);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == 0);
}

void displayArrayQueue(ArrayQueue* pQueue)
{
    int i = pQueue->front;

    printf("max size [%d]\n\n", pQueue->maxElementCount);
	printf("curr size [%d]\n\n", pQueue->currentElementCount);
	printf("front : %d \n", pQueue->front);
	printf("rear : %d \n", pQueue->rear );
    printf("isempty : %d\n", isArrayQueueEmpty(pQueue));
	printf("isfull : %d\n", isArrayQueueFull(pQueue));
    
    // printf("|%c", pQueue->pElement[i++].data);
    while(pQueue->rear != i)
    {
        i = (i + 1) % pQueue->maxElementCount;
        printf("|%c", pQueue->pElement[i].data);
    }
	// printf("|%c", pQueue->pElement[i].data); //
    printf("\n");
}
