#include "linkedgraph.h"

// 무방향 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->currentEdgeCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList *) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = NULL;
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}

// 방향 그래프 생성
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->currentEdgeCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->ppAdjEdge = (LinkedList**)malloc(sizeof(LinkedList *) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = NULL;
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph)
{
	// ppAdjEdge
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList(pGraph->ppAdjEdge[i]);
	// pVertex
	free(pGraph->pVertex);
	// pGraph
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	// if (vertexID >= pGraph->maxVertexCount)
	// {
	// 	return (FALSE);
	// }
	// return (pGraph->pVertex[vertexID] == USED);
	if (vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == NOT_USED)
		return (FALSE);
	return (TRUE);
}

// 연결리스트 생성: 주황색 (headerNode)
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	ListNode element;
	// 노드 유효성 확인
	// if (!checkVertexValid(pGraph, vertexID))
	// {
	// 	printf(": check\n");
	// 	return (FALSE);
	// }
	if (vertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (FALSE);
	pGraph->pVertex[vertexID] = USED;
	// printf("addVertexLG : %d\n",pGraph->currentVertexCount);
	if (pGraph->ppAdjEdge[vertexID] == NULL)
		pGraph->ppAdjEdge[vertexID] = createLinkedList();
	else
		return (FALSE);
	pGraph->currentVertexCount++;
	return (TRUE);
}

// 가중치 간선 추가: 보라색
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	ListNode element;
	// 노드의 유효성 점검: from, to
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	element.data = toVertexID;
	element.weight = weight;
	addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, element);
	pGraph->currentEdgeCount++;
	// 그래프의 타입 = 무방향
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		element.data = fromVertexID;
		element.weight = weight;
		addLLElement(pGraph->ppAdjEdge[toVertexID], 0, element);
		pGraph->currentEdgeCount++;
	}
	return (TRUE);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	return(addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 0));
}

int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	int pos;
	ListNode *cur;

	pos = 0;
	cur = (&pList->headerNode)->pLink;
	while (cur)
	{
		if (cur->data == vertexID)
			return (pos);
		cur = cur->pLink;
		pos++;
	}
	return (-1);
}

// deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID)
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int pos;

	pos = findGraphNodePosition(pList, delVertexID);
	if (pos == -1)
		return ;
	removeLLElement(pList, pos);
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	// int pos;

	// 노드의 유효성 점검: from, to
	// if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
	// 	return (FALSE);
	if (fromVertexID >= pGraph->maxVertexCount)
		return (FALSE);
	if (pGraph->pVertex[fromVertexID] == NOT_USED)
		return (FALSE);
	deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	// pos = findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	// if (pos == 0)
	// 	return (FALSE);
	// removeLLElement(pGraph->ppAdjEdge[fromVertexID], pos);
	pGraph->currentEdgeCount--;
	// 그래프의 타입 = 무방향
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		// pos = findGraphNodePosition(pGraph->ppAdjEdge[toVertexID], fromVertexID);
		// if (pos == 0)
		// 	return (FALSE);
		// removeLLElement(pGraph->ppAdjEdge[toVertexID], pos);
		pGraph->currentEdgeCount--;
	}
	return (TRUE);
}
// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	// 지우고자하는 노드가 USED인지 확인
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	// 간선을 지우는: 반복문 : free & NULL
	deleteLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->ppAdjEdge[vertexID] = NULL;
	// 노드: NOT_USED
	pGraph->pVertex[vertexID] = NOT_USED;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
			removeEdgeLG(pGraph, i, vertexID);
	}
	pGraph->currentVertexCount--;
	return (TRUE);
}




// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}
// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}
// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}
// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (pGraph->graphType == GRAPH_DIRECTED)
		return (GRAPH_DIRECTED);
	else
		return (GRAPH_UNDIRECTED);
}
// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			printf("[%d]: ", i);
			// printf(": %d\n", pGraph->ppAdjEdge[i]->currentElementCount);
			displayLinkedList(pGraph->ppAdjEdge[i]);
		}
	}
	printf("\n");
}
