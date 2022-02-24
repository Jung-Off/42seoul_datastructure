#include "binsearch.h"

int main()
{
    BinTreeNode node = {0,0,0,0};
    BinTree *tree = NULL;
    BinTreeNode *pNode;

    while(1)
    {
        int input;
        char data;
        // BinTreeNode *save = NULL;
        printf("1. create | 2. getRootNode | 3. insertLeft | 4. insertRight |\n");
        printf("5. getChild Left | 6.getChild Right | 7. deleteNode | 8. deleteTree | 9. printTree | 0. exit\n");
        printf("Type Menu : ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                fflush(stdin);
                printf("head input : ");
                node.data = getchar();
                tree = makeBinTree(node);
                break;
            case 2:
                printf("getRootNode!!!!\n");
                pNode = getRootNodeBT(tree);
                printf("head node data: %d\n", pNode->data);
                break;
            case 3:
                printf("Type data you want to insert\n");
                fflush(stdin);
                node.data = getchar();
                insertNode(tree, node);
                break;
            case 5:
                printf("Type data you want to find\n");
                fflush(stdin);
                data = getchar();
                pNode = findNode(tree->pRootNode, data);
                if (!pNode)
                    printf("ERROR: No node\n");
                if (!pNode->pLeftChild )
                    printf("ERROR: node\n");
                else
                {
                    printf("%p\n", getLeftChildNodeBT(pNode));
                    printf("Left : %c\n", getLeftChildNodeBT(pNode)->data); 
                }
                break;
            case 6:
                printf("Type data you want to find\n");
                fflush(stdin);
                data = getchar();
                pNode = findNode(tree->pRootNode, data);
                if (!pNode)
                    printf("ERROR: No node\n");
                if (!pNode->pRightChild)
                    printf("ERROR: No Right node\n");
                else
                {
                    printf("%p\n", getRightChildNodeBT(pNode));
                    printf("Right : %c\n", (getRightChildNodeBT(pNode))->data);
                }
                break;
            case 7:
                printf("Type data you want to find\n");
                fflush(stdin);
                data = getchar();
                pNode = findNode(tree->pRootNode, data);
                deleteBinTreeNode(pNode);
                // pNode = NULL;
                // 문제가 있다!
                break;
            case 8:
                deleteBinTree(tree);
                tree = NULL;
                break;
            case 9:
                printTree(tree);
                break;
            case 0:
                exit(1);
        }
    }
}