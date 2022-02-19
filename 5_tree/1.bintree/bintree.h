#ifndef _BIN_TREE_
#define _BIN_TREE_

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

BinTree* makeBinTree(BinTreeNode rootNode); //헤드노드 만드는
BinTreeNode* getRootNodeBT(BinTree* pBinTree);  //헤드 반환
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element); //왜 node?
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);
void printNode(BinTreeNode* node);
BinTreeNode* findNode(BinTreeNode *node, char data);
void printTree(BinTree* tree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif