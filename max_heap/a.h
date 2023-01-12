// Max heap
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Element;

int n;
int capacity;
Element* heap;
Element* list;

void init();

void sort();

void push(const Element);
Element pop();
Element peek();

void printHeap();
void printList();

void release();