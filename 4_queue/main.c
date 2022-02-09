#include "arrayqueue.h"

int main()
{
    ArrayQueue* head = NULL;
    ArrayQueueNode element = {0};
    int input;
    int maxElementCount;

    while(1)
    {
        printf("\n1.create | 2. enqueue | 3.dequeue | 4.peek | 0.exit\n");
        printf("input num : ");
        scanf("%d", &input);
        fflush(stdin);

        if (input == 1)
        {
            int max;
            printf("max size ! : ");
            scanf("%d", &max);
            head = createArrayQueue(max);
            if (!head)
            {
                printf("stack is empty!\n");
                return 0;
            }
        }
        else if(input == 2)
        {
            printf("input_element (char): ");
            element.data = getchar();
            enqueueAQ(head, element);
            displayArrayQueue(head);
        }
        else if (input == 3)
        {
            ArrayQueueNode* del;
            del = dequeueAQ(head);
            free(del);
            displayArrayQueue(head);
        }
        else if(input == 4)
        {
            ArrayQueueNode* peek;
            peek = peekAQ(head);
            printf("this is peek\n");
            printf("[ %c ]\n", peek->data);
        }
        else if (input == 0)
        {
            printf("exit\n");
            deleteArrayQueue(head);
            exit(0);
        }
    }
}