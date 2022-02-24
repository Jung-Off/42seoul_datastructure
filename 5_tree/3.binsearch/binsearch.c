
#include "binsearch.h"

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

// BinTreeNode* insertNode(BinTree* tree, BinTreeNode element)
// {
//     BinTreeNode *curr;
//     BinTreeNode *parent;
//     BinTreeNode *res = malloc(sizeof(BinTreeNode));
//     if (res == NULL)
//         return (NULL);
//     *res = element;

//     if (tree->pRootNode == NULL)
//     {
//         tree->pRootNode = res;
//         return (res);
//     }
    
//     curr = tree->pRootNode;
//     while (curr)
//     {
//         parent = curr;
//         if (res->data < curr->data)
//             curr = curr->pLeftChild;
//         else if (res->data > curr->data)
//             curr = curr->pRightChild;
//         else //(res->data == curr->data)
//         {
//             printf("Error: Key already exist\n");
//             free (res);
//             res = NULL;
//             return NULL;
//         }
//     }
//     if (res->data < parent->data)
//         parent->pLeftChild = res;
//     else
//         parent->pRightChild = res;
// 	return (res);
// }

BinTreeNode* newNode(char key)
{
    BinTreeNode *node = malloc(sizeof(BinTreeNode));
    if (node == NULL)
        return (NULL);
    node->data = key;
    return (node);
}

BinTreeNode* insertNode(BinTreeNode *node, char key)
{
    if (node == NULL)
        return (newNode(key));
//    else if (node->data == key)
//        return (node);
    else if (node->data > key)
        node->pLeftChild = insertNode(node->pLeftChild, key);
    else if (node->data < key)
        node->pRightChild = insertNode(node->pRightChild, key);
    return (node);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode && pNode->pLeftChild)
        return (pNode->pLeftChild);
    printf("no left child!\n");
    return (NULL);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode && pNode->pRightChild)
        return (pNode->pRightChild);
    printf("no right child!\n");    
    return (NULL);
}

static BinTreeNode* getMinValue(BinTreeNode* rootNode)
{
    BinTreeNode* res;

    res = rootNode;
    while (res->pLeftChild)
        res = res->pLeftChild;
    return (res);
}

BinTreeNode* deleteBinTreeNode(BinTreeNode* pNode, char key)
{
    if (!pNode)
        return (NULL);
    if (pNode->data > key)
        pNode->pLeftChild = deleteBinTreeNode(pNode->pLeftChild, key);
    else if (pNode->data < key)
        pNode->pRightChild = deleteBinTreeNode(pNode->pRightChild, key);
    else
    {
        BinTreeNode* temp = NULL;
        if (pNode->pLeftChild == NULL)
        {
            temp = pNode->pRightChild;
            free(pNode);
            return (temp);
        }
        else if (pNode->pRightChild == NULL)
        {
            temp = pNode->pLeftChild;
            free(pNode);
            return (temp);
        }
        temp = getMinValue(pNode->pRightChild);
        pNode->data = temp->data;
        deleteBinTreeNode(pNode->pRightChild, temp->data);
    }
    return(pNode);
}

//자식이 둘 부모 둘 > 붙일수가 없어서 이렇게 생각!
void clearBinTreeNode(BinTreeNode* pNode)
{
    //  if (!pNode->pLeftChild && !pNode->pRightChild)
    // {
    //     free(pNode);
    //     return ;
    // }
    if (!pNode)
        return ;
    if (pNode->pLeftChild)
    {
        clearBinTreeNode(pNode->pLeftChild);
        pNode->pLeftChild = NULL;
    }
    if (pNode->pRightChild)
    {
        clearBinTreeNode(pNode->pRightChild);
        pNode->pRightChild = NULL;
    }
    free(pNode);
}

void deleteBinTree(BinTree** pBinTree)
{
    clearBinTreeNode((*pBinTree)->pRootNode);
    (*pBinTree)->pRootNode = NULL;
    free(*pBinTree);
    *pBinTree = NULL;
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
    else
        printf("no tree\n");
}

BinTreeNode* findNode(BinTree* tree, char data)
{
    BinTreeNode *curr;

    curr = tree->pRootNode;
    while (curr)
    {
        if (data < curr->data)
            curr = curr->pLeftChild;
        else if (data > curr->data)
            curr = curr->pRightChild;
        else //(res->data == curr->data)
        {
            printf("Find it!\n");
            return (curr);
        }
    }
    printf("Error: Do not exist\n");
    return (NULL);
}