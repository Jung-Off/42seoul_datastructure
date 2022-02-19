
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTreeNode *data = malloc(sizeof(BinTreeNode));
    if (data == NULL)
        return (NULL);
    *data = rootNode;

    BinTree *head = malloc(sizeof(BinTree));
    if (head == NULL)
    {
        free(data);
        return (NULL);
    }
    head->pRootNode = data;
    return (head);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if (pBinTree)
        return (pBinTree->pRootNode);
    printf("ERROR: Root Node is NULL");
    return (NULL);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *data = malloc(sizeof(BinTreeNode));
    if (data == NULL)
        return (NULL);
    *data = element;
    pParentNode->pLeftChild = data;
    return (pParentNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *data = malloc(sizeof(BinTreeNode));
    if (data == NULL)
        return (NULL);
    *data = element;
    pParentNode->pRightChild = data;
    return (pParentNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode)
        return (pNode->pLeftChild);
    return (NULL);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode)
        return (pNode->pRightChild);
    return (NULL);
}

//자식이 둘 부모 둘 > 붙일수가 없어서 이렇게 생각!
void deleteBinTreeNode(BinTreeNode* pNode)
{
    // BinTreeNode* delNode;
    // delNode = pNode;
     if (pNode == NULL)
    {
        printf("end point\n");    
        return ;
    }
    if (pNode->pLeftChild)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        pNode->pLeftChild = NULL;
    }
    if (pNode->pRightChild)
    {
        deleteBinTreeNode(pNode->pRightChild);
        pNode->pRightChild = NULL;
    }
    free(pNode);
}

void deleteBinTree(BinTree* pBinTree)
{
    deleteBinTreeNode(pBinTree->pRootNode);
    pBinTree->pRootNode = NULL;
    free(pBinTree);
    // pBinTree = NULL;
}

void printpreorder(BinTreeNode* node)
{
    if (node)
    {
        printf("[%c]", node->data);
        printpreorder(node->pLeftChild);
        printpreorder(node->pRightChild);  
    }
}

void printinorder(BinTreeNode* node)
{
    if (node)
    {
        printinorder(node->pLeftChild);
        printf("[%c]", node->data);
        printinorder(node->pRightChild);  
    }
}

void printpostorder(BinTreeNode* node)
{
    if (node)
    {
        printpostorder(node->pLeftChild);
        printpostorder(node->pRightChild);  
        printf("[%c]", node->data);
    }
}

void printTree(BinTree* tree)
{
    if (tree)
    {
        printf("preorder");
        printpreorder(tree->pRootNode);
        printf("\ninorder");
        printinorder(tree->pRootNode);
        printf("\npostorder");
        printpostorder(tree->pRootNode);
        printf("\n");
    }
}

BinTreeNode* findNode(BinTreeNode* node, char data)
{
    BinTreeNode *save = NULL;

    if (!node)
        return (save);
    printf("node data: %c\n", node->data);
    if (node->data == data)
        save = node;
    if (save == NULL)
        save = findNode(node->pLeftChild, data);
    if (save == NULL)
        save = findNode(node->pRightChild, data);
    // printf("%d\n", save->data);
    return (save);
}