// Quick Sort
#include "a.h"

int main()
{
	init();
	sort(0, n - 1);
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

void sort(const int left, const int right)
{
	if (right <= left)
		return;

	printList(left, -2, right);
	int i = left;
	int j = right + 1;

	while (true)
	{
		do i++; while (list[i] < list[left]);
		do j--; while (list[j] > list[left]);

		if (i >= j)
			break;

		swap(&list[i], &list[j]);
	}
	swap(&list[left], &list[j]);
	
	printList(left, j, right);
	sort(left, j - 1);
	sort(j + 1, right);
}

void swap(Element* element1, Element* element2)
{
	Element temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void printList(const int left, const int mid, const int right)
{
	for (int i = 0; i < n; i++)
	{
		char lparen = ' ';
		char rparen = ' ';
		
		if (i == mid)
		{
			lparen = '(';
			rparen = ')';
		}
		else
		{
			if (i == left || i == mid + 1)
				lparen = '[';
			if (i == right || i == mid - 1)
				rparen = ']';
		}
		
		printf("%c%2d%c", lparen, list[i], rparen);
	}
	printf("\n");
}

void add(const Element element)
{
	list[n++] = element;
}

void release()
{
	free(list);
}