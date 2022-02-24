#include "binsearch.h"

BinTreeNode* deleteBinTreeNode(BinTree* ptree, char key)
{
    BinTreeNode* curr;
	BinTreeNode* parent;

    if (!ptree)
        return (NULL);
	curr = ptree->pRootNode;
	while (curr)
    {
        parent = curr;
        if (key < curr->data)
            curr = curr->pLeftChild;
        else if (key > curr->data)
            curr = curr->pRightChild;
        else
            break ;
    }
	if (!curr)
		return (NULL);
	if (curr->pLeftChild && curr->pRightChild)	//자식이 둘 다 있음
	{
		
	}
	else if(curr->pLeftChild)	//자식이 하나만 있음
	{
		if (parent->pLeftChild == curr)
			parent->pLeftChild = curr->pLeftChild; //curr에서 자식노드로의 링크 삭제가 있어야 함
		else
			parent->pRightChild = curr->pLeftChild;
	}
	else if(curr->pRightChild)
	{
		if (parent->pLeftChild == curr)
			parent->pLeftChild = curr->pRightChild;
		else
			parent->pRightChild = curr->pRightChild;		
	}
	else
	{
		if (parent->pLeftChild == curr)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
	}
	return (curr);

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
//         tree->pRootNode = res;
// 	else
// 	{
// 		curr = tree->pRootNode;
// 		while (curr)
// 		{
//             parent = curr;
// 			if (res->data < curr->data)
// 				curr = curr->pLeftChild;
// 			else if (res->data > curr->data)
// 				curr = curr->pRightChild;
// 			else //(res->data == curr->data)
// 			{
// 				free (res);
// 				res = NULL;
// 				return NULL;
// 			}
// 		}
// 		if (res->data < parent->data)
//             parent->pLeftChild = res;
//         else
//             parent->pRightChild = res;
        
// 	}
// 	return (res);
// }