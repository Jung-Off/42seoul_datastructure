#include "circlelist.h"

CircularList* createCircularList()
{
    CircularList *List;

    List = (CircularList *)malloc(sizeof(CircularList));
    
    List->currentElementCount = 0;
    List->headerNode = NULL;
    return List;
}
