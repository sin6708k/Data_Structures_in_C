// Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef int Element;

int capacity;
int n;
Element* list;
Element* sorted;

void init();

void sort(const int, const int);
void merge(const int, const int, const int);
void swap(Element*, Element*);

void add(const Element);

void printList(const int, const int, const int);

void release();