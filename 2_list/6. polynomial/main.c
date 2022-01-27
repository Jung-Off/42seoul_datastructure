#include "linkedlist.h"

void print_list(LinkedList *head)
{
    ListNode *Node = head->headerNode.pLink;

    // printf("\nThis list length : %d\n", getLinkedListLength(head));
    // printf("[head]\n");
    while (Node)
    {
        printf("%.f x^%d ", Node->coef, Node->degree);
        Node = Node->pLink;
        if (Node != NULL)
           printf("+ "); 
    }
    // printf("(NULL)");
    printf("\n\n");
}

void print_hello(void)
{
   printf("descending order polynomial circulator!\n");
}

LinkedList *add(LinkedList* a, LinkedList* b)
{
    LinkedList *c = createLinkedList();
    ListNode *a_temp = a->headerNode.pLink;
    ListNode *b_temp = b->headerNode.pLink;

    while (a_temp != NULL && b_temp != NULL)
    {
        if (a_temp->degree > b_temp->degree)
        {
            addPolyNodeLast(c, a_temp->coef, a_temp->degree);
            a_temp = a_temp->pLink;
        }
        else if (a_temp->degree < b_temp->degree)
        {
            addPolyNodeLast(c, b_temp->coef, b_temp->degree);
            b_temp = b_temp->pLink;
        }
        else
        {
            int coef_temp = a_temp->coef + b_temp->coef;
            addPolyNodeLast(c, coef_temp, a_temp->degree);
            a_temp = a_temp->pLink;
            b_temp = b_temp->pLink;
        }
    }

    ListNode *temp;
    if (a_temp == NULL)
        temp = b_temp;
    else
        temp = a_temp;

    while (temp != NULL)
    {
        addPolyNodeLast(c, temp->coef, temp->degree);
        temp = temp->pLink;
    }
    return (c);
}

int main()
{

    LinkedList *poly1;
    LinkedList *poly2;
    int coef;
    int degree;
    poly1 = createLinkedList();
    poly2 = createLinkedList();

    print_hello();
        
    while (1)
    {
        printf("\npolynominal 1\n\n");
        printf("coefficient : ");
        scanf("%d", &coef);
        if (coef == 0)
            break;
        printf("degree : ");
        scanf("%d", &degree);
        // if (degree == 0)
        //     break;
        addPolyNodeLast(poly1, coef, degree);
        print_list(poly1);
    }
    printf("\n");
    while (1)
    {
        printf("polynominal 2\n\n");
        printf("coefficient : ");
        scanf("%d", &coef);
        if (coef == 0)
            break;
        printf("degree : ");
        scanf("%d", &degree);
        // if (degree == 0)
        //     break;
        addPolyNodeLast(poly2, coef, degree);
        print_list(poly2);
    }
    printf("poly1 ========\n");
    print_list(poly1);
    printf("poly2 ========\n");
    print_list(poly2);

    LinkedList *poly3 = add(poly1, poly2);

    print_list(poly3);

    deleteLinkedList(poly1);
    poly1 = NULL;

    deleteLinkedList(poly2);
    poly2 = NULL;

    deleteLinkedList(poly3);
    poly3 = NULL;

    printf("bye bye\n");
}