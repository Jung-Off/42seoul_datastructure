#include "linkeddeque.h"

int main()
{
    LinkedDeque* head = NULL;
    DequeNode element = {0};
    int input;
    int maxElementCount;

    while(1)
    {
        printf("\n1.create | 2. insertFront | 3. insertRear | 4.peek | 5. delete front | 6. delete rear\n"); 
        printf("input num : ");
        scanf("%d", &input);
        fflush(stdin);

        if (input == 1)
        {
            // int max;
            // printf("max size ! : ");
            // scanf("%d", &max);
            head = createLinkedDeque();
            if (!head)
            {
                printf("stack is empty!\n");
                return 0;
            }
        }
        else if (input == 2)
        {
            printf("input_element (char): ");
            element.data = getchar();
            insertFrontLD(head, element);
            displayDeque(head);
            reversedisplay(head);
        }
        else if (input == 3)
        {
            printf("input_element (char): ");
            element.data = getchar();
            insertRearLD(head, element);
            displayDeque(head);
            reversedisplay(head);
        }
        else if(input == 4)
        {
            DequeNode* peek1;
            peek1 = peekFrontLD(head);
            printf("this is peek Front : ");
            printf("[ %c ]\n\n", peek1->data);
            DequeNode* peek2;
            peek2 = peekRearLD(head);
            printf("this is peek Rear : ");
            printf("[ %c ]\n", peek2->data);
        }
        else if(input == 5)
        {
            deleteFrontLD(head);
            displayDeque(head);
            reversedisplay(head);
        }
        else if(input == 6)
        {
            deleteRearLD(head);
            displayDeque(head);
            reversedisplay(head);
        }
        else if (input == 0)
        {
            printf("exit\n");
            deleteArrayQueue(head);
            exit(0);
        }
    }
}