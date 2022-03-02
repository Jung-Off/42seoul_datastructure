#include "arraygraph.h"

// typedef struct ArrayGraphType {

// 	int maxVertexCnt; // 최대 노드 개수
// 	int curVertexCnt; // 현재까지 사용된 노드 개수
// 	int graphType;   // 그래프의 종류- 1 -> 무방향 ,2 -> 방향 그래프
// 	int** ppAdjEdge; // 간선을 저장하는 2차원 배열
// 	int* pVertex;    // 노드를 저장하는 1차원 배열
// } ArrayGraph;

// 무방향 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	pGraph->maxVertexCnt = maxVertexCount;
	pGraph->curVertexCnt = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}

// 방향 그래프 생성
ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;

	pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	pGraph->maxVertexCnt = maxVertexCount;
	pGraph->curVertexCnt = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
	for (int i = 0; i < maxVertexCount; i++)
		pGraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	pGraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (pGraph);
}


// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	// pVertex
	free(pGraph->pVertex);
	// ppAdjEdge
	for (int i = 0; i < pGraph->maxVertexCnt; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	// pGraph
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->curVertexCnt == 0);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	// vertexID 타당성 확인
	if (vertexID < 0 && vertexID >= pGraph->maxVertexCnt)
		return (FALSE);
	// vertexID 사용 유무확인
	if (pGraph->pVertex[vertexID] != USED)
		pGraph->pVertex[vertexID] = USED;
	else
	{
		printf("node already used\n");
		return (FALSE);
	}
	pGraph->curVertexCnt++;
	return (TRUE);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (vertexID >= pGraph->maxVertexCnt)
		return (FALSE);
	if (pGraph->pVertex[vertexID] == USED)
		return (TRUE);
	// return (pGraph->pVertex[vertexID] == USED);
	return (FALSE);
}

// 가중치 간선 추가
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	// 노드의 유효성 점검: from, to
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	// ppAdjEdge[fromVertexID][toVertexID]
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	// 그래프의 타입 = 무방향
	// ppAdjEdge[toVertexID][fromVertexID]
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, 1));

}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, 0));
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	// 지우고자하는 노드가 USED인지 확인
	if (!checkVertexValid(pGraph, vertexID))
	{
		printf("not used!\n");
		return (FALSE);
	}
	// 간선을 지우는: 반복문
	for (int i = 0; i < pGraph->maxVertexCnt; i++)
	{
		pGraph->ppAdjEdge[i][vertexID] = 0;
		pGraph->ppAdjEdge[vertexID][i] = 0;
	}
	// 노드: NOT_USED
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->curVertexCnt--;
	return (TRUE);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	printf("   ");
	for (int i = 0; i < pGraph->maxVertexCnt; ++i)
		printf("%d ", i);
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCnt; ++i)
	{
		printf("%d: ", i);
		for (int j = 0; j < pGraph->maxVertexCnt; ++j)
		{
			if (pGraph->pVertex[i] == NOT_USED || pGraph->pVertex[j] == NOT_USED)
				printf("X ");
			else
				printf("%d ", pGraph->ppAdjEdge[i][j]);
		// if (pGraph->pVertex[i] == NOT_USED)
		// 	printf(" NOT USED");
		}
		printf("\n");
	}
}

