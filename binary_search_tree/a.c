// Binary Search Tree
#include "a.h"

int main()
{
	init();
	searchOnBinTree();
	release(binTree);
	return 0;
}

void init()
{
	FILE* file = fopen("input.txt", "r");
	while (!feof(file))
	{
		Element element;
		fscanf(file, "%d", &element);
		push(&binTree, element);

		printf("push(%2d) -> ", element);
		printBinTree(binTree);
		printf("\n");
	}
	printf("\n");
	fclose(file);
}

void searchOnBinTree()
{
	while (true)
	{
		Element element;
		printf("element to find is ");
		scanf("%d", &element);

		if (element < 0)
			return;
		
		printf("search(%2d) -> ", element);
		printf("\nresult is %s\n\n",
			searchOnNodes(binTree, element) ? "succeed" : "fail");	
	}
}

bool searchOnNodes(const BinTreeNode* const node, const Element element)
{
	if (node == NULL)
		return false;
	
	printf("%2d ", node->element);
	
	if (element < node->element)
		return searchOnNodes(node->leftChild, element);
		
	else if (node->element < element)
		return searchOnNodes(node->rightChild, element);
		
	else if (node->element == element)
		return true;
}

void push(BinTreeNode** node, const Element element)
{
	if (*node == NULL)
	{
		BinTreeNode* newNode = malloc(sizeof(*newNode));
		newNode->element = element;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		*node = newNode;
		return;
	}

	if ((*node)->element >= element)
	{
		push(&(*node)->leftChild, element);
	}
	else
	{
		push(&(*node)->rightChild, element);
	}
}

void printBinTree(const BinTreeNode* const node)
{
	if (node == NULL)
		return;

	printBinTree(node->leftChild);
	printf("%2d ", node->element);
	printBinTree(node->rightChild);
}

void release(BinTreeNode* node)
{
	if (node == NULL)
		return;

	release(node->leftChild);
	release(node->rightChild);
	free(node);
}