// The Satisfiability Problem
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BinTreeNode
{
	char symbol;
	int value;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
} BinTreeNode;

typedef struct StackNode
{
	BinTreeNode* data;
	struct StackNode* link;
} StackNode;

BinTreeNode* binTree;
char postfix[100];
StackNode* top;

void init();

void inorder(const BinTreeNode*);
void setValue(BinTreeNode*, const int, const int, const int);
int evaluate(BinTreeNode*);

void push(BinTreeNode* const);
BinTreeNode* pop();
BinTreeNode* peek();

void printList();

void release(BinTreeNode*);