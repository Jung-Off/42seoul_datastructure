
#include "circlelist.h"

void print_circle(CircularList *head)
{
    CircularListNode *Node = head->headerNode;
    CircularListNode *first = head->headerNode;

    printf("Length : %d\n", head->currentElementCount);

    if (head->headerNode == 0)
    {
        printf("head empty!\n");
        return ;
    }
    printf("[head pointer] -> ");
    while (1)
    {
        printf("[%d] -> ", Node->data);

        Node = Node->pRlink;
        if (Node == first)
        {
            printf("[END] -> ");
            printf("[%d] ", Node->data);
            break;
        }
    }
    printf("\n\n");
}

CircularListNode* getDLElement(CircularList* pList, int position)
{
    if (position >= pList->currentElementCount || position < 0)
    {
        printf("not found\n");
        return (NULL);
    }

    CircularListNode *move = pList->headerNode;

    int pos = position;
    while (pos > 0)
    {
        move = move->pRlink;
        --pos;
    }
    return (move);
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
    CircularList *head;
    CircularListNode input_node = {0, 0};

    int c;
    int position = 0;

    head = createCircularList();

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

            addDLElement(head, position, input_node);
            print_circle(head);
        }
        else if (c == 2)
        {
            printf("input delete data! : ");
            scanf("%d", &position);
            removeDLElement(head, position);
            print_circle(head);
        }
        else if (c == 3)
        {
            CircularListNode *temp = NULL;
            printf("where is it? :");
            scanf("%d", &position);
            temp = getDLElement(head, position);
            if (temp != NULL)
            {
                printf("\n");
                printf("position    :   %d\n", position);
                printf("data        :   %d\n", temp->data);
            }
        }
        else if (c == 4)
        {
            clearCircularList(head);
            // print_circle(head);
        }
        else if (c == 5)
            displayCircularList(head);
        else if (c == 0)
        {
            deleteCircularList(head);
            print_circle(head);
        	break;
        }
    }
    printf("bye bye!\n");
}