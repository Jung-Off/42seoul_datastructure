#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{   
    //position = 0; �� ��� ���!
    if (position >= pList->currentElementCount || position < 0)
    {
        printf("not found\n");
        return (NULL);
    }
    
    ListNode *move = &(pList->headerNode);
    
    int pos = position;
    while (pos > 0)
	{
			move = move->pLink;
			pos--;
	}

    return (move->pLink);
}
