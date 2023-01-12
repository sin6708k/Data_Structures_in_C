// Static Hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Element
{
	int key;
	char item[20];
} Element;

typedef struct Node
{
	Element data;
	struct Node* link;
} Node;

Node** hashTable;
int capacity;

void init();
void insert(const Element);

Node* createNode(const Element);
Node* emptyNode();

Element createElement(const char*);
Element emptyElement();

void printTable();
void printNodes(const Node*);

Node* searchOnTable(const int);
Node* searchOnNodes(Node* const, const int);
Node* searchLastOnNodes(Node* const);
Node* searchPrevOnNodes(Node* const, const int);

int convertItemToKey(const char*);
int getHashCode(const int, const int);

void releaseTable();
void releaseNodes(Node*);

void deleteOnTable(const int);