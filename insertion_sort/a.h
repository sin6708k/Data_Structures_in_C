// Insertion Sort
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Element;

int capacity;
int n;
Element* list;

void init();

void sort();

void add(const Element);

void printList(const int, const int);

void release();