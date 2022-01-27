#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
	float coef;
	int degree;
	struct ListNodeType* pLink;
} ListNode;					//생성되는 것! LinkedList 뒤에 붙여줄 것!

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();											//생성하기
int addLLElement(LinkedList* pList, int position, ListNode element);	//	추가하기
int removeLLElement(LinkedList* pList, int position);					//	지우기
ListNode* getLLElement(LinkedList* pList, int position);				//	요소 찾기
void clearLinkedList(LinkedList* pList);								//	노드 다 지우기 List만 남긴다.
int getLinkedListLength(LinkedList* pList);								//	길이
void deleteLinkedList(LinkedList* pList);
int addPolyNodeLast(LinkedList *pList, float coef, int degree);								//	List를 지운다
// void reverseLinkedList(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif