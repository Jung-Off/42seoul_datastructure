
#ifndef _BIN_SEARCH_
#define _BIN_SEARCH_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


typedef struct BinTreeNodeType
{
	char data;
	int visited;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode); 
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* newNode(char key);
BinTreeNode* insertNode(BinTreeNode *node, char key);
// BinTreeNode* insertNode(BinTree* tree, BinTreeNode element);
//>> insert만
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree** pBinTree); //중간거 빼기 가능!
BinTreeNode* deleteBinTreeNode(BinTreeNode* pNode, char key);
void clearBinTreeNode(BinTreeNode* pNode);
void printNode(BinTreeNode* node);
BinTreeNode* findNode(BinTree *node, char data);
void printTree(BinTree* tree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif