#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;					//생성되는 것! LinkedList 뒤에 붙여줄 것!

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

LinkedList* createLinkedList();
// 헤더 노드만을 가리키는 화살표
int addLLElement(LinkedList* pList, int position, ListNode element);
//					  v
// 헤더 노드를 처음으로해서 ㅁ-ㅁ-ㅁ-ㅁ


int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);


#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif