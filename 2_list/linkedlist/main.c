#include "linkedlist.h"

void print_list(LinkedList *head)
{
    ListNode *Node = head->headerNode.pLink;
    printf("==%d==\n", head->currentElementCount);
    while (Node)
    {
        printf("[%d] -> ", Node->data);
        Node = Node->pLink;
    }
    printf("(NULL)");
    printf("\n");
}

void print_command(void)
{
    printf("1. add element\n");
    printf("2. delete element\n");
    printf("push command! : ");
}

int main()
{

    LinkedList *head;
    int c;                  //command
    int position = 0;       //넣을 위치 받아오는 변수
    head = createLinkedList();
    ListNode node0 = {0, 0}; //이부분 참고! // data로 무엇을 넣을지 계속 바꿔주는 것! add함수안에서 말록으로 넣어서 지역변수로 재활용해서 사용이 가능!

    while (1)
    {
        print_command();
        scanf("%d", &c);

        if (c == 1)
        {
            printf("input data! : ");
            scanf("%d", &(node0.data));

            printf("input where! : ");
            scanf("%d", &position);

            addLLElement(head, position, node0);
            print_list(head);
        }
        else if (c == 2)
        {
            printf("delete where! : ");
            scanf("%d", &position);

            removeLLElement(head, position);
            print_list(head);
        }
        else if (c == 0)
            break;
    }
    printf("bye bye\n");
}