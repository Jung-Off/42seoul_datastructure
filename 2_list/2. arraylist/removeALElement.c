
#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
        return (FALSE);
    //  ������ ����
    memmove(&(pList->pElement[position]), &(pList->pElement[position + 1]), 
        sizeof(ArrayListNode) * (pList->currentElementCount - position - 1));
    //  �޺κ� �ʱ�ȭ?
    //  ��¥�� �Ⱥ��̴ϱ� ����� ������?

    pList->currentElementCount--;
    return (TRUE);
}