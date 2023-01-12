// Merge Sort
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
	sorted = malloc(sizeof(*sorted) * capacity);

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
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	printList(left, mid, right);
	sort(left, mid);
	sort(mid + 1, right);
	merge(left, mid, right);
	printList(left, -2, right);
}

void merge(const int left, const int mid, const int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid)
		memcpy(sorted + k, list + j, sizeof(*sorted) * (right - j + 1));
	else
		memcpy(sorted + k, list + i, sizeof(*sorted) * (mid - i + 1));

	memcpy(list + left, sorted + left, sizeof(*list) * (right - left + 1));
}

void swap(Element* element1, Element* element2)
{
	Element temp = *element1;
	*element1 = *element2;
	*element2 = temp;
}

void add(const Element element)
{
	list[n++] = element;
}

void printList(const int left, const int mid, const int right)
{
	for (int i = 0; i < n; i++)
	{
		char lparen;
		char rparen;

		if (i == left || i == mid + 1)
			lparen = '[';
		else
			lparen = ' ';

		if (i == right || i == mid)
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
	free(sorted);
}