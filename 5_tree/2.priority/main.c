#include "priority.h"

int main()
{
    pHeap *heap = createHeap(3);
    
    pHNode element5 = {'d'};
    pHNode element6 = {'h'};
    pHNode element7 = {'g'};
    pHNode element8 = {'i'};

    insertElement(heap, element5);
    printHeap(heap);
    insertElement(heap, element6);
    printHeap(heap);
    insertElement(heap, element7);
    printHeap(heap);
    insertElement(heap, element8);
    printHeap(heap);

    pHNode element1 = {'c'};
    pHNode element2 = {'b'};
    pHNode element3 = {'d'};
    pHNode element4 = {'a'};
    insertElement(heap, element1);
    printHeap(heap);
    insertElement(heap, element2);
    printHeap(heap);
    insertElement(heap, element3);
    printHeap(heap);
    insertElement(heap, element4);
    printHeap(heap);

    pHNode* dequeue = deleteElement(heap);
    printf("dequeue: %c\n", dequeue->data);
    printHeap(heap);
    dequeue = deleteElement(heap);
    printf("dequeue: %c\n", dequeue->data);
    printHeap(heap);
    dequeue = deleteElement(heap);
    printf("dequeue: %c\n", dequeue->data);
    printHeap(heap);
    dequeue = deleteElement(heap);
    printf("dequeue: %c\n", dequeue->data);
    printHeap(heap);
}