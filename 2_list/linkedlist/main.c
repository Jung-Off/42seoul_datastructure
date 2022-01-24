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
    int position = 0;       //���� ��ġ �޾ƿ��� ����
    head = createLinkedList();
    ListNode node0 = {0, 0}; //�̺κ� ����! // data�� ������ ������ ��� �ٲ��ִ� ��! add�Լ��ȿ��� �������� �־ ���������� ��Ȱ���ؼ� ����� ����!

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