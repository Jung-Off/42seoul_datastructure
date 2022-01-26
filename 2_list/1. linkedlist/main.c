#include "linkedlist.h"

void print_list(LinkedList *head)
{
    ListNode *Node = head->headerNode.pLink;

    printf("\nThis list length : %d\n", getLinkedListLength(head));
    printf("[head] -> ");
    while (Node)
    {
        printf("[%d] -> ", Node->data);
        Node = Node->pLink;
    }
    printf("(NULL)");
    printf("\n\n");
}

void print_command(void)
{
    printf("1. add element\n");
    printf("2. delete element\n");
    printf("3. get element\n");
    printf("4. clear list\n");
    printf("push command! : ");
}

int main()
{

    LinkedList *head;
    int c;                  //command
    int position = 0;       //넣을 위치 받아오는 변수
    head = createLinkedList();
    ListNode input_node = {0, 0}; //이부분 참고! // data로 무엇을 넣을지 계속 바꿔주는 것! add함수안에서 말록으로 넣어서 지역변수로 재활용해서 사용이 가능!

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

            addLLElement(head, position, input_node);
            print_list(head);
        }
        else if (c == 2)
        {
            printf("delete where! : ");
            scanf("%d", &position);

            removeLLElement(head, position);
            print_list(head);
        }
        else if (c == 3)
        {
            printf("Where is it? : ");
            scanf("%d", &position);

            ListNode *node_copy;
            node_copy = getLLElement(head, position);
            if (node_copy != NULL)
            {
                printf("\n");
                printf("position    :   %d\n", position);
                printf("data        :   %d\n", node_copy->data);
                printf("\n");
            }
        }
        else if(c == 4)
        {
            clearLinkedList(head);
            print_list(head);
        }
        else if (c == 0)
            break;
    }

    deleteLinkedList(head);
    head = NULL;

    printf("bye bye\n");
}