
#include "doublylist.h"

DoublyList* createDoublyList()
{
    DoublyList *new;

    new = (DoublyList *)malloc(sizeof(DoublyList));
    
    new->currentElementCount = 0;
    new->headerNode.data = 0;
    new->headerNode.pLLink = 0;
    new->headerNode.pRLink = 0;
    return new;
}

// void deleteDoublyList(DoublyList* pList)
// {

// }

// int removeDLElement(DoublyList* pList, int position)
// {

// }

// void clearDoublyList(DoublyList* pList)
// {

// }

int getDoublyListLength(DoublyList* pList)
{
    return (pList->currentElementCount);
}

// DoublyListNode* getDLElement(DoublyList* pList, int position)
// {

// }

void displayDoublyList(DoublyList* pList)
{
    DoublyListNode *temp;
    DoublyListNode *temp_right;
    DoublyListNode *temp_left;

    temp = &(pList->headerNode);

    temp_right = pList->headerNode.pRLink; //오른쪽 0번
    temp_left = pList->headerNode.pLLink;   //왼쪽 0번
    printf("Length : %d\n", pList->currentElementCount);
    printf("[시작]\n");
    printf("[head]right -> ");
    // printf("%d ", pList->headerNode.pRLink->data);
    while (temp_right != temp)
    {
        printf("[ %d ] -> ", temp_right->data);
        temp_right = temp_right->pRLink;
    }
    printf("[head] \n");

    printf("[head]left -> ");
    // printf("%d ", pList->headerNode.pLLink->data);
    while (temp_left != temp)
    {
        printf("[ %d ] -> ", temp_left->data);
        temp_left = temp_left->pLLink;
    }
    printf("[head] \n");
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
    DoublyListNode *temp;

    if (position < 0 || position > pList->currentElementCount)
        return (FALSE);
    
    temp = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    
    temp->data = element.data;
    temp->pLLink = &(pList->headerNode);
    temp->pRLink = &(pList->headerNode);
    
    if (pList->headerNode.pRLink == NULL)
    {
        pList->headerNode.pRLink = temp;
        pList->headerNode.pLLink = temp;
    }
    else
    {
        if (position == 0)
        {
            temp->pRLink = pList->headerNode.pRLink;
            pList->headerNode.pRLink = temp;
            temp->pLLink = &pList->headerNode;
            temp->pRLink->pLLink = temp;
        }
        else if (position <= pList->currentElementCount)
        {
            DoublyListNode *add_before = &(pList->headerNode);

            int i = 0;
            while (i < position)
            {
                add_before = add_before->pRLink;
                ++i;
            }
            temp->pRLink = add_before->pRLink;
            add_before->pRLink = temp;
            temp->pRLink->pLLink = temp;
            temp->pLLink = add_before;
        }
        // else
        // {
        //     DoublyListNode *add_before = &(pList->headerNode);

        //     int i = 0;
        //     while (i < position)
        //     {
        //         add_before = add_before->pRLink;
        //         ++i;
        //     }
            
        //     temp->pRLink = add_before->pRLink;
        //     add_before->pRLink = temp;
        //     temp->pRLink->pLLink = temp;
        //     temp->pLLink = add_before;
        // }
    }
    pList->currentElementCount++;
    return (TRUE);
}

void print_command(void)
{
    printf("1. add element\n");
    // printf("2. delete element\n");
    // printf("3. get element\n");
    // printf("4. clear list\n");
    // printf("5. show list\n");
    printf("push command! : ");
}

int main()
{
    DoublyList *temp;
    DoublyListNode input_node = {0, 0, 0};

    int c;
    int position = 0;

    temp = createDoublyList();

    while (1)
    {  
         print_command();
        printf("Command typing : ! ");
        scanf("%d", &c);

        if (c == 1)
        {
            printf("intput data! : ");
            scanf("%d", &(input_node.data));

            printf("input where! : ");
            scanf("%d", &position);

            addDLElement(temp, position, input_node);
            displayDoublyList(temp);
        }
        // else if (c == 2)
        // {
        //     printf("input delete data! : ");
        //     scanf("%d", &position);
        //     removeDLElement(temp, position);
        //     displayDoublyList(temp);
        // }
         else if (c == 3)
        {
            DoublyListNode *temp_temp = NULL;
            printf("where is it? :");
            scanf("%d", &position);
            temp_temp = getDLElement(temp, position);
            if (temp != NULL)
            {
                printf("\n");
                printf("position    :   %d\n", position);
                printf("data        :   %d\n", temp_temp->data);
            }
        }
        // else if (c == 4)
        // {
        //     clearDoublyList(temp);
        //     displayDoublyList(head);
        // }
        // else if (c == 5)
        //     displayDoublyList(temp);
        else if (c == 0)
        {
            // deleteCircularList(temp);
            // displayDoublyList(temp);
            break;
        }

    }
    printf("bye bye!\n");
}