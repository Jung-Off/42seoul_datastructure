#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *List;

    List = (LinkedList *)malloc(sizeof(LinkedList));
    List->currentElementCount = 0;

    //think headerNode == NULL (���� �ʱ�ȭ �� �� ����)
    List->headerNode.data = 0;
    List->headerNode.pLink = NULL;
    return (List);
}