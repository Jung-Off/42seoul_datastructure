#include "linkedgraph.h"
#include "linkedeque.h"

# define VISITED 1
# define NOT_VISITED 0


LinkedList* reverseLinkedList(LinkedList *pList)
{
    if (pList->headerNode.pLink == NULL)
    {
        printf("empty !");
        return NULL;
    }
    if (pList->currentElementCount == 1)
        return (pList);
    // printf("reverse!\n");

    ListNode *prev;
    ListNode *curr;
    ListNode *next;

	// v
	// 1>	2>	3
	// ㅁ - ㅁ - ㅁ
	// 			v
	// 3>	2>	1
	// ㅁ - ㅁ - ㅁ

    prev = 0;
    next = 0;
    curr = pList->headerNode.pLink;
	// printf("re: %d %d\n", pList->headerNode.pLink->data, pList->headerNode.pLink->pLink->data);
    while (curr)
    {
        next = curr->pLink;
        if (prev == NULL)
            curr->pLink = NULL;
        else
            curr->pLink = prev;

        prev = curr;
        curr = next;
    }
	// 왜?? prev로 설정
	// https://www.geeksforgeeks.org/reverse-a-linked-list/
	pList->headerNode.pLink = prev;
	// printf("re: %d %d\n", pList->headerNode.pLink->data, pList->headerNode.pLink->pLink->data);
	displayLinkedList(pList);
	return(pList);
}


void	breadthFindSearch(LinkedGraph *pGraph, int startVertex)
{
	LinkedDeque *pQueue;
	DequeNode element;
	DequeNode *dequeue;
	ListNode *curr;
	LinkedList *temp;
	int pVisted[pGraph->maxVertexCount];
	int idx;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
		pVisted[i] = NOT_VISITED;
	pQueue = createLinkedDeque();
	// 시작 방문 (사용)노드을  스택에 담기
	element.data = startVertex;
	pVisted[startVertex] = VISITED;
	insertRearLD(pQueue, element);
	// 반복문: 스택이 비어졌는지 확인
	while (!isLinkedDequeEmpty(pQueue))
	{
		dequeue = deleteFrontLD(pQueue);
		printf("%d ", dequeue->data);
		// curr = pGraph->ppAdjEdge[dequeue->data]->headerNode.pLink;
		temp = reverseLinkedList(pGraph->ppAdjEdge[dequeue->data]);
		// displayLinkedList(temp);
		curr = temp->headerNode.pLink;
		while (curr)
		{
			if (pVisted[curr->data] == NOT_VISITED)
			{
				element.data = curr->data;
				pVisted[curr->data] = VISITED;
				insertRearLD(pQueue, element);
			}
			curr = curr->pLink;
		}
	}
}

LinkedGraph *make_graph(void)
{
	LinkedGraph *pGraph;
	int i;

	pGraph = createLinkedGraph(8);
	i = 0;
	while (i < pGraph->maxVertexCount)
		addVertexLG(pGraph, i++);
	addEdgeLG(pGraph, 0, 1);
	addEdgeLG(pGraph, 0, 2);
	addEdgeLG(pGraph, 1, 3);
	addEdgeLG(pGraph, 1, 4);
	addEdgeLG(pGraph, 2, 5);
	addEdgeLG(pGraph, 2, 6);
	addEdgeLG(pGraph, 3, 7);
	addEdgeLG(pGraph, 4, 5);
	addVertexLG(pGraph, 6);
	// printf("info: %d %d\n", pGraph->currentVertexCount, pGraph->currentEdgeCount);
	displayLinkedGraph(pGraph);
	printf("\n");
	// removeEdgeLG(pGraph, 5, 3);
	// removeVertexLG(pGraph, 2);
	// removeVertexLG(pGraph, 3);
	// addVertexLG(pGraph, 2);
	// displayLinkedGraph(pGraph);
	// deleteLinkedGraph(pGraph);
	return (pGraph);
}

int main(void)
{
	LinkedGraph *pGraph;

	pGraph = make_graph();
	breadthFindSearch(pGraph, 0);
	return (0);
}
