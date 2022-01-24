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
    element4.data = 3;
    element4.pLink = NULL;

    ListNode element5;
    element5.data = 4;
    element5.pLink = NULL;

    addLLElement(head, 0, element1);
    {   
        ListNode *Node = head->headerNode.pLink;
        printf("==%d==\n", head->currentElementCount);
        while (Node)
        {
            printf("[%d] -> ", Node->data);
            Node = Node->pLink;
        }
        printf("(NULL)");
        printf("\n");
    }
    addLLElement(head, 0, element2);
    {   
        ListNode *Node = head->headerNode.pLink;
        printf("==%d==\n", head->currentElementCount);
        while (Node)
        {
            printf("[%d] -> ", Node->data);
            Node = Node->pLink;
        }
        printf("(NULL)");
        printf("\n");
    }
    addLLElement(head, 0, element3);
    {   
        ListNode *Node = head->headerNode.pLink;
        printf("==%d==\n", head->currentElementCount);
        while (Node)
        {
            printf("[%d] -> ", Node->data);
            Node = Node->pLink;
        }
        printf("(NULL)");
        printf("\n");
    }
    addLLElement(head, 3, element4);
    {   
        ListNode *Node = head->headerNode.pLink;
        printf("==%d==\n", head->currentElementCount);
        while (Node)
        {
            printf("[%d] -> ", Node->data);
            Node = Node->pLink;
        }
        printf("(NULL)");
        printf("\n");
    }
    addLLElement(head, 4, element5);
    {   
        ListNode *Node = head->headerNode.pLink;
        printf("==%d==\n", head->currentElementCount);
        while (Node)
        {
            printf("[%d] -> ", Node->data);
            Node = Node->pLink;
        }
        printf("(NULL)");
        printf("\n");
    }

}