
#include "arraylist.h"

void print_arr(ArrayList *pList)
{
    // int i = 0;

    printf("\n");
    printf("Full size : %d\n", pList->maxElementCount);
    printf("isArrayListFull? ");
    printf(isArrayListFull(pList) ? "YES\n" : "NO\n");
    printf("length : %d", getArrayListLength(pList));
    printf("\n");

    displayArrayList(pList);
    // while (i < pList->currentElementCount)
    // {
    //     printf("[%d] ", pList->pElement[i].data);
    //     ++i;
    // }
    printf("\n");
}

void print_command(void)
{
    printf("1. add element\n");
    printf("2. delete element\n");
    printf("3. get element\n");
    printf("4. clear list\n");
    printf("5. show list\n");
    printf("push command! : ");
}

int main()
{
    int position = 0;
    int c;

    printf("create ArratList (max size) : ");
    scanf("%d", &c);
    ArrayList *list = createArrayList(c);

    ArrayListNode input_node = {0};    
    while (1)
    {
        print_command();
        scanf("%d", &c);
        if (c == 1)
        {
            printf("input data! : ");
            scanf("%d", &(input_node.data));

            printf("input where! : ");
            scanf("%d", &position);

            addALElement(list, position, input_node);
            print_arr(list);
        }
        else if (c == 2)
        {
            printf("input delete data! : ");
            scanf("%d", &position);
            removeALElement(list, position);
            print_arr(list);
        }
        else if (c == 3)
        {
            ArrayListNode *temp;
            printf("where is it? :");
            scanf("%d", &position);
            temp = getALElement(list, position);
            if (temp != NULL)
            {
                printf("\n");
                printf("position    :   %d\n", position);
                printf("data        :   %d\n", temp->data);
            }
        }
        else if (c == 4)
            clearArrayList(list);
        else if (c == 5)
            displayArrayList(list);
        else if (c == 0)
            break;
    }
    deleteArrayList(list);
    printf("bye bye");

    return 0;
}