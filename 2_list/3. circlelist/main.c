#include <stdio.h>
#include "circlelist.h"

void print_circle(CircularList *head)
{
    CircularListNode *Node = head->headerNode;
    CircularListNode *first = head->headerNode;

    printf("Length : %d\n", head->currentElementCount);

    if (head->headerNode == NULL)
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

int main()
{
    CircularList *head;
    CircularListNode input_node = {0, 0};

    int c;
    int position = 0;

    head = createCircularList();

    while (1)
    {
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
        else if (c == 0)
        	break;
    }

}