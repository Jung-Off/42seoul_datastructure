#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayGraphType {

	int maxVertexCnt; // 최대 노드 개수
	int curVertexCnt; // 현재까지 사용된 노드 개수
	int graphType;   // 그래프의 종류- 1 -> 무방향 ,2 -> 방향 그래프
	int** ppAdjEdge; // 간선을 저장하는 2차원 배열
	int* pVertex;    // 노드를 저장하는 1차원 배열
} ArrayGraph;

// 무방향 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount);
// 방향 그래프 생성
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);
// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
// 가중치 간선 추가
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);


// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph);
// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph);

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID);
// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
