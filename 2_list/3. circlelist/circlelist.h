#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* pRlink;
} CircularListNode;

typedef struct CircularListType
{
	int	currentElementCount;		// 현재 저장된 원소의 개수
	CircularListNode*   headerNode;		// 헤더 노드(Header Node)
} CircularList;

CircularList* createCircularList();	//
void deleteCircularList(CircularList* pList); // 다지우기
int addDLElement(CircularList* pList, int position, CircularListNode element);	//
int removeDLElement(CircularList* pList, int position); //원소하나
void clearCircularList(CircularList* pList);	//깔끔하게
int getCircularListLength(CircularList* pList); //
CircularListNode* getDLElement(CircularList* pList, int position); //
void displayCircularList(CircularList* pList); //`

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif