#include "linkedlist.h"

LinkedList* createLinkedList(void)
{
    LinkedList  *List;

    List = (LinkedList *)malloc(sizeof(LinkedList));
    List->currentElementCount = 0;

    //think headerNode == NULL (으로 초기화 될 수 없음)
    List->headerNode.coef = 0;
    List->headerNode.degree = 0;
    List->headerNode.pLink = NULL;
    return (List);
}