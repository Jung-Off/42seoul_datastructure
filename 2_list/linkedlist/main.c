#include "linkedlist.h"

ListNode* createListNode(int a)
{
    ListNode  *Node;

    Node = (ListNode *)malloc(sizeof(ListNode));
    Node->data = a;
    Node->pLink = NULL;

    return (Node);
}

int main()
{
    LinkedList *head;

    head = createLinkedList();

    ListNode element1;
    element1.data = 0;
    element1.pLink = NULL;

    ListNode element2;
    element2.data = 1;
    element2.pLink = NULL;

    ListNode element3;
    element3.data = 2;
    element3.pLink = NULL;

    ListNode element4;
    element3.data = 3;
    element3.pLink = NULL;

    ListNode element5;
    element3.data = 4;
    element3.pLink = NULL;

    addLLElement(head, 0, element1);
    addLLElement(head, 1, element2);
    // addLLElement(head, 2, element3);
    // addLLElement(head, 3, element4);
    // addLLElement(head, 4, element5);

    ListNode *Node = &(head->headerNode);
    printf("==%d==\n", head->currentElementCount);
    while (Node)
    {
        printf("[%d]\n", Node->data);
        Node = Node->pLink;
    }
}