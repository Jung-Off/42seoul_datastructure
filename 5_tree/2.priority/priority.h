
#ifndef PRIORITY_H
#define PRIORITY_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct HeapNodeType
{
    char data;
} pHNode;

typedef struct HeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	pHNode *pElement;	// 원소 저장을 위한 1차원 배열
} pHeap;

pHeap *createHeap(int level);
//반환 값을 true/false로 할 지, insert한 index를 반환할 지
int insertElement(pHeap* heap, pHNode element);
pHNode* deleteElement(pHeap* heap);
pHNode* getElement(pHeap* heap, int index);
void clearHeap(pHeap* heap);
void deleteHeap(pHeap* heap);
void printHeap(pHeap* heap);
int isHeapFull(pHeap* heap);
int isHeapEmpty(pHeap* heap);
int compare(pHNode node1, pHNode node2);

#define TRUE    1
#define FALSE   0

#endif