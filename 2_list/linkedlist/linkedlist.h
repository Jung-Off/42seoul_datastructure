#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;					//�����Ǵ� ��! LinkedList �ڿ� �ٿ��� ��!

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode headerNode;		// ��� ���(Header Node)
} LinkedList;

LinkedList* createLinkedList();											//�����ϱ�
int addLLElement(LinkedList* pList, int position, ListNode element);	//	�߰��ϱ�
int removeLLElement(LinkedList* pList, int position);					//	�����
ListNode* getLLElement(LinkedList* pList, int position);				//	��� ã��
void clearLinkedList(LinkedList* pList);								//	��� �� ����� List�� �����.
int getLinkedListLength(LinkedList* pList);								//	����
void deleteLinkedList(LinkedList* pList);								//	List�� �����

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif