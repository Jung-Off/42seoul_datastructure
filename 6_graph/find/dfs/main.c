#include "linkedgraph.h"
#include "linkedstack.h"

// typedef struct StackNodeType
// {
// 	char data;
// 	struct StackNodeType* pLink;
// } StackNode;

// typedef struct LinkedStackType
// {
// 	int currentElementCount;	// 현재 원소의 개수
// 	StackNode* pTopElement;		// Top 노드의 포인터
// } LinkedStack;

// LinkedStack* createLinkedStack();

// int pushLS(LinkedStack* pStack, StackNode element);
// StackNode* popLS(LinkedStack* pStack);
// StackNode* peekLS(LinkedStack* pStack);

// void deleteLinkedStack(LinkedStack* pStack);

// int isLinkedStackFull(LinkedStack* pStack);
// int isLinkedStackEmpty(LinkedStack* pStack);

// void displayLinkedStack(LinkedStack *pStack);
# define VISITED 1
# define NOT_VISITED 0


void	depthFindSearch(LinkedGraph *pGraph, int startVertex)
{
	LinkedStack *pStack;
	StackNode element;
	StackNode *pop;
	ListNode *curr;
	LinkedList *temp;
	int pVisted[pGraph->maxVertexCount];

	for (int i = 0; i < pGraph->maxVertexCount; i++)
		pVisted[i] = NOT_VISITED;
	pStack = createLinkedStack();
	// 시작 방문 (사용)노드을  스택에 담기
	element.data = startVertex;
	pVisted[startVertex] = VISITED;
	pushLS(pStack, element);
	// 반복문: 스택이 비어졌는지 확인
	while (!isLinkedStackEmpty(pStack))
	{
		pop = popLS(pStack);
		printf("%d ", pop->data);
		curr = pGraph->ppAdjEdge[pop->data]->headerNode.pLink;
		while (curr)
		{
			if (pVisted[curr->data] == NOT_VISITED)
			{
				element.data = curr->data;
				pVisted[curr->data] = VISITED;
				pushLS(pStack, element);
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
	depthFindSearch(pGraph, 0);
	return (0);
}
