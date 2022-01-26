
#include "circlelist.h"

void clearCircularList(CircularList* pList)
{
    if (pList->headerNode == 0)
    {
        printf("empty!\n");
        return ;
    }
   
    CircularListNode* first = pList->headerNode;
    CircularListNode* temp = NULL;
    CircularListNode* move = NULL;

    pList->currentElementCount = 0;
    move = first->pRlink;

    while (first != move)
    {
        temp = move->pRlink;
        free(move);
        move = temp;
    }
        free(move);
        pList->headerNode = NULL;
        //first = NULL;
        //둘은 엄연히 다른 의미!
    
    
    //temp = pList->headerNode;
    // while (temp)
    // {
    //     next = temp->pRlink;
    // //     free(temp);
    //     temp = next;
    // }
    //이런식의 구성이면 double free...

}