// Insertion Sort
#include "a.h"

int main()
{
	init();
	sort();
	release();
	return 0;
}

void init()
{
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &capacity);

	n = 0;
	list = malloc(sizeof(*list) * capacity);
	
	for (int i = 0; i < capacity; i++)
	{
		Element element;
		fscanf(file, "%d", &element);
		add(element);
	}
	fclose(file);
}

void sort()
{
	for (int i = 0; i < n; i++)
	{
		const Element temp = list[i];

		int j;
		for (j = i - 1; j >= 0 && list[j] > temp; j--)
			list[j + 1] = list[j];
		
		list[j + 1] = temp;

		printList(0, i);
	}
}

void add(const Element element)
{
	list[n++] = element;
}

void printList(const int left, const int right)
{
	for (int i = 0; i < n; i++)
	{
		char lparen;
		char rparen;

		if (i == left)
			lparen = '[';
		else
			lparen = ' ';

		if (i == right)
			rparen = ']';
		else
			rparen = ' ';
		
		printf("%c%2d%c", lparen, list[i], rparen);
	}
	printf("\n");
}

void release()
{
	free(list);
}