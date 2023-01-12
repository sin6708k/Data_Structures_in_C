// The Satisfiability Problem
#include "a.h"

int main()
{
	init();
	printList();
	release(binTree);
	return 0;
}

void init()
{
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%s", postfix);
	printf("f(a, b, c) with postfix = %s\n", postfix);

	for (char* symbol = postfix; *symbol != '\0'; symbol++)
	{
		BinTreeNode* node = malloc(sizeof(*node));
		node->symbol = *symbol;

		if (*symbol == '~') // NOT
		{
			node->rightChild = pop();
			node->leftChild = NULL;
		}
		else if (*symbol == '&') // AND
		{
			node->rightChild = pop();
			node->leftChild = pop();
		}
		else if (*symbol == '|') // OR
		{
			node->rightChild = pop();
			node->leftChild = pop();
		}
		else
		{
			node->rightChild = NULL;
			node->leftChild = NULL;
		}

		push(node);
	}
	binTree = pop();
	
	printf("f(a, b, c) with infix = ");
	inorder(binTree);
	printf("\n\n");
	
	fclose(file);
}

void inorder(const BinTreeNode* node)
{
	if (node == NULL)
		return;
	
	inorder(node->leftChild);
	printf("%c", node->symbol);
	inorder(node->rightChild);
}

void setValue(BinTreeNode* node, const int a, const int b, const int c)
{
	if (node == NULL)
		return;

	if (node->symbol == 'a')
	{
		node->value = a;
	}
	else if (node->symbol == 'b')
	{
		node->value = b;
	}
	else if (node->symbol == 'c')
	{
		node->value = c;
	}
	else
	{
		node->value = -1;
	}

	setValue(node->leftChild, a, b, c);
	setValue(node->rightChild, a, b, c);
}

int evaluate(BinTreeNode* node)
{
	if (node == NULL)
		return -1;

	int leftValue = evaluate(node->leftChild);
	int rightValue = evaluate(node->rightChild);

	if (node->symbol == '~') // NOT
	{
		node->value = !rightValue;
		return node->value;
	}
	else if (node->symbol == '&') // AND
	{
		node->value = leftValue && rightValue;
		return node->value;
	}
	else if (node->symbol == '|') // OR
	{
		node->value = leftValue || rightValue;
		return node->value;
	}
	else
	{
		return node->value;
	}
}

void push(BinTreeNode* const data)
{
	StackNode* node = malloc(sizeof(*node));
	node->data = data;
	
	if (top)
	{
		node->link = top;
	}
	else
	{
		node->link = NULL;
	}

	top = node;
}

BinTreeNode* pop()
{
	if (top == NULL)
		return NULL;

	StackNode* deletedNode = top;
	BinTreeNode* binTree = deletedNode->data;
	top = deletedNode->link;
	free(deletedNode);
	return binTree;
}

BinTreeNode* peek()
{
	if (top == NULL)
		return NULL;

	return top->data;
}

void printList()
{
	for (int a = 0; a <= 1; a++)
	{
		for (int b = 0; b <= 1; b++)
		{
			for (int c = 0; c <= 1; c++)
			{
				setValue(binTree, a, b, c);
				printf("f(%d, %d, %d) = %d\n", a, b, c, evaluate(binTree));
			}
		}
	}
}

void release(BinTreeNode* node)
{
	if (node == NULL)
		return;

	release(node->leftChild);
	release(node->rightChild);
	free(node);
}