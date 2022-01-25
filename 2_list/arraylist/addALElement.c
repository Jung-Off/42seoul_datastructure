
#include "arraylist.h"

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
    if (position > pList->currentElementCount || isArrayListFull(pList) || position < 0) // 가득 찾을 때!
        return (FALSE);
    
    //  뒤로 옮기기
    memmove(&(pList->pElement[position + 1]), &(pList->pElement[position]),
        sizeof(ArrayListNode) * (pList->currentElementCount - position));
    //  빈자리에 끼워 넣기
    memcpy(&(pList->pElement[position]), &element, sizeof(ArrayListNode));
    //element의 주소에서 sizeof 만큼 position에 붙여 넣기
    pList->currentElementCount++;
    return (TRUE);
}