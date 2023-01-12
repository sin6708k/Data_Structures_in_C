// Static Hashing
#include "a.h"

int main()
{
	init();
	printTable();
	releaseTable();
	return 0;
}

void init()
{
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &capacity);
	
	hashTable = malloc(sizeof(*hashTable) * capacity);
	for (int i = 0; i < capacity; i++)
	{
		hashTable[i] = emptyNode();
	}

	while (!feof(file))
	{
		char item[20];
		fscanf(file, "%s", item);
		insert(createElement(item));
	}
	fclose(file);
}

void insert(const Element element)
{
	int hashCode = getHashCode(element.key, capacity);
	Node* prevNode = searchLastOnNodes(hashTable[hashCode]);
	Node* newNode = createNode(element);
	newNode->link = prevNode->link;
	prevNode->link = newNode;
}

Node* createNode(const Element data)
{
	Node* node = malloc(sizeof(*node));
	node->data = data;
	node->link = NULL;
	return node;
}

Node* emptyNode()
{
	return createNode(emptyElement());
}

Element createElement(const char* item)
{
	Element element;
	element.key = convertItemToKey(item);
	strcpy(element.item, item);
	return element;
}

Element emptyElement()
{
	return createElement("");
}

void printTable()
{
	for (int i = 0; i < capacity; i++)
	{
		printf("%3d : ", i);
		printNodes(hashTable[i]);
		printf("\n");
	}
}

void printNodes(const Node* node)
{
	if (node == NULL)
		return;

	if (node->data.key)
		printf("(%d, %s) ", node->data.key, node->data.item);

	printNodes(node->link);
}

Node* searchOnTable(const int key)
{
	const int hashCode = getHashCode(key, capacity);
	return searchOnNodes(hashTable[hashCode], key);
}

Node* searchOnNodes(Node* const node, const int key)
{
	if (node == NULL)
		return NULL;

	if (node->data.key == key)
		return node;

	return searchOnNodes(node->link, key);
}

Node* searchLastOnNodes(Node* const node)
{
	if (node == NULL)
		return NULL;

	if (node->link == NULL)
		return node;

	return searchLastOnNodes(node->link);
}

Node* searchPrevOnNodes(Node* const node, const int key)
{
	if (node == NULL)
		return NULL;

	if (node->link == NULL)
		return NULL;

	if (node->link->data.key == key)
		return node;

	return searchPrevOnNodes(node, key);
}

int convertItemToKey(const char* item)
{
	int key = 0;

	while (*item)
		key += *(item++);

	return key;
}

int getHashCode(const int key, const int capacity)
{
	return key % capacity;
}

void releaseTable()
{
	for (int i = 0; i < capacity; i++)
		releaseNodes(hashTable[i]);
	
	free(hashTable);
}

void releaseNodes(Node* node)
{
	if (node == NULL)
		return;

	releaseNodes(node->link);
	free(node);
}

void deleteOnTable(const int key)
{
	const int hashCode = getHashCode(key, capacity);
	Node* prevNode = searchPrevOnNodes(hashTable[hashCode], key);

	if (prevNode == NULL)
		return;

	Node* deletedNode = prevNode->link;
	prevNode->link = deletedNode->link;
	free(deletedNode);
}