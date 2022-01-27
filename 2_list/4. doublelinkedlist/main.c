
#include "doublylist.h"

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
        else if (c == 2)
        {
            printf("input delete data! : ");
            scanf("%d", &position);
            removeDLElement(temp, position);
            displayDoublyList(temp);
        }
         else if (c == 3)
        {
            DoublyListNode *temp_temp = NULL;
            printf("where is it? : ");
            scanf("%d", &position);
            temp_temp = getDLElement(temp, position);
            if (temp_temp != NULL)
            {
                printf("\n");
                printf("position    :   %d\n", position);
                printf("data        :   %d\n", temp_temp->data);
            }
        }
        else if (c == 4)
        {
            clearDoublyList(temp);
            displayDoublyList(temp);
        }
        else if (c == 5)
            displayDoublyList(temp);
        else if (c == 0)
        {
            deleteDoublyList(temp);
            displayDoublyList(temp);
            break;
        }

    }
    printf("bye bye!\n");
}