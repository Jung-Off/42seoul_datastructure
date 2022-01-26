
#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    if (position > pList->currentElementCount || isArrayListFull(pList) || position < 0) // ���� ã�� ��!
        return (FALSE);
    
    //  �ڷ� �ű��
    memmove(&(pList->pElement[position + 1]), &(pList->pElement[position]),
        sizeof(ArrayListNode) * (pList->currentElementCount - position));
    //  ���ڸ��� ���� �ֱ�
    memcpy(&(pList->pElement[position]), &element, sizeof(ArrayListNode));
    //element�� �ּҿ��� sizeof ��ŭ position�� �ٿ� �ֱ�
    pList->currentElementCount++;
    return (TRUE);
}