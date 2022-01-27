
#include "doublylist.h"

void displayDoublyList(DoublyList* pList)
{
    DoublyListNode *temp;
    DoublyListNode *temp_right;
    DoublyListNode *temp_left;

    if (pList->headerNode.pRLink == NULL)
    {
        printf("isempty!\n");
        return;
    }

    temp = &(pList->headerNode);

    temp_right = pList->headerNode.pRLink; //오른쪽 0번
    temp_left = pList->headerNode.pLLink;   //왼쪽 0번
    printf("Length : %d\n", pList->currentElementCount);
    printf("[시작]\n");
    printf("[head]right -> ");
    // printf("%d ", pList->headerNode.pRLink->data);
    while (temp_right != temp)
    {
        printf("[ %d ] -> ", temp_right->data);
        temp_right = temp_right->pRLink;
    }
    printf("[head] \n");

    printf("[head]left -> ");
    // printf("%d ", pList->headerNode.pLLink->data);
    while (temp_left != temp)
    {
        printf("[ %d ] -> ", temp_left->data);
        temp_left = temp_left->pLLink;
    }
    printf("[head] \n");
}
