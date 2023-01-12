// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef int Element;

typedef struct BinTreeNode
{
	Element element;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
} BinTreeNode;

BinTreeNode* binTree;

void init();

void searchOnBinTree();
bool searchOnNodes(const BinTreeNode* const, const Element);

void push(BinTreeNode**, const Element);

void printBinTree(const BinTreeNode* const);

void release(BinTreeNode*);