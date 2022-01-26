
#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
        return (FALSE);
    //  앞으로 당기기
    memmove(&(pList->pElement[position]), &(pList->pElement[position + 1]), 
        sizeof(ArrayListNode) * (pList->currentElementCount - position - 1));
    //  뒷부분 초기화?
    //  어짜피 안보이니까 상관이 없을까?

    pList->currentElementCount--;
    return (TRUE);
}