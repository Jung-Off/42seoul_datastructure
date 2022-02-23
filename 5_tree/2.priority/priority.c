#include "priority.h"

pHeap *createHeap(int level)
{
    pHeap *res;

    if (level == 0)
        return (NULL);
    res = malloc(sizeof(pHeap));
    if (!res)
        return NULL;
    // printf("power: %d", (int)pow(2, level));
    res->maxElementCount = pow(2, level);
    res->currentElementCount = 0;
    res->pElement = calloc(pow(2, level), sizeof(pHNode));
    if (!res->pElement)
    {
        free(res);
        return NULL;
    }
    return (res);
}

//min tree
int compare(pHNode node1, pHNode node2)
{
    if (node1.data >= node2.data)
        return (TRUE);
    return (FALSE);
}

void printHeap(pHeap* heap)
{
    // printf("Print Array\n");
    for (int i = 1; i <= heap->currentElementCount; i++)
        printf("[%d] : %c ", i, heap->pElement[i].data);
    printf("\n");
}

int insertElement(pHeap* heap, pHNode element)
{
    int insert = heap->currentElementCount + 1;
    pHNode swap;

    if (!heap || !heap->pElement)
        return (FALSE);
    //if Array is Full;
    if (isHeapFull(heap))
    {
        pHNode *temp = heap->pElement;
        heap->pElement = calloc((pow(2, log2(heap->maxElementCount) + 1)), sizeof(pHNode));
        if (!heap->pElement)
            return (FALSE);
        heap->pElement = temp;
        free(temp);
        heap->maxElementCount = (heap->maxElementCount) * 2;
    }
    heap->pElement[insert] = element;
    heap->currentElementCount++;
    if (isHeapEmpty(heap))
        return (TRUE);    
    // printf("============\n");
    // printHeap(heap);
    while (insert >= 2)
    {
        if (compare(heap->pElement[insert / 2], heap->pElement[insert]))
        {
            swap = heap->pElement[insert];
            heap->pElement[insert] = heap->pElement[insert / 2];
            heap->pElement[insert / 2] = swap;
            // printHeap(heap);
        }
        insert /= 2;
    }
    // printf("============\n");
    return (TRUE);
}

int isHeapFull(pHeap* heap)
{
    if (heap->currentElementCount == heap->maxElementCount - 1)
        return (TRUE);
    return (FALSE);
}

int isHeapEmpty(pHeap* heap)
{
    if (heap->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

#include "priority.h"

pHNode* deleteElement(pHeap* heap)   //index 불필요한 것 같다
{
    pHNode* res;
    int     s;

    if (!heap || !heap->pElement || isHeapEmpty(heap))
        return (NULL);
    res = malloc(sizeof(pHNode));
    if (!res)
        return (NULL);
    *res = heap->pElement[1];
    heap->pElement[1] = heap->pElement[heap->currentElementCount];
    heap->currentElementCount--;
    //printf("-------start-------\n");
    for (int i = 1; i < heap->currentElementCount;)
    {
        //자식체크 1. 자식이 없음 2. 자식이 왼쪽만 있음 3. 자식이 둘 다 있음
      	if (i * 2 >= heap->currentElementCount)
			break ;
        else if (i * 2 == heap->currentElementCount)
			s = i * 2;
		else
        {
            if (compare(heap->pElement[i * 2], heap->pElement[i * 2 + 1]))  //sibling 비교
                s = i * 2 + 1;
            else
                s = i * 2;
            //printf("s = %d\n", s);
        }
        //비교 체크 - 바꿔야 함 / 더 이상 안 바꿔도 됨
                                //부모              //자식
        if (compare(heap->pElement[s / 2], heap->pElement[s]))  //부모 자식 비교
        {
            pHNode swap;
            swap = heap->pElement[s];
            heap->pElement[s] = heap->pElement[s / 2];
            heap->pElement[s / 2] = swap;
		    i = s;
            //printHeap(heap);
        }
        else
            break ;
    }
   // printf("----------------\n");
    return (res);
}

void clearHeap(pHeap* heap)
{
    for (int i = 0; i < heap->maxElementCount; ++i)
        heap->pElement[i].data == 0;
    heap->currentElementCount == 0;
}

void deleteHeap(pHeap* heap)
{
    free(heap->pElement);
    heap->pElement = NULL;
    free(heap);
}