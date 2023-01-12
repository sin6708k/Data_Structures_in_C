// Max Heap
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
	heap = malloc(sizeof(*heap) * (capacity + 1));
	list = malloc(sizeof(*list) * capacity);
	
	while (!feof(file))
	{
		Element element;
		fscanf(file, "%d", &element);
		push(element);

		printf("push(%2d)\n", element);
		printHeap();
	}
	fclose(file);
}

void sort()
{
	for (int i = 0; n > 0; i++)
	{
		Element element = pop();
		list[i] = element;
		printf("pop(%2d) ->\n", element);
		printHeap();
	}
	printList();
}

void push(const Element element)
{
	int i = ++n;
	for (; i != 1; i /= 2)
	{
		if (element < heap[i / 2])
			break;

		heap[i] = heap[i / 2];
	}
	heap[i] = element;
}

Element pop()
{
	const Element deleted = heap[1];
	const Element temp = heap[n];
	heap[n--] = INT_MIN;

	int parent = 1;
	for (int child = 2; child <= n; parent = child, child *= 2)
	{
		if (child + 1 <= n && heap[child] < heap[child + 1])
			child++;

		if (temp >= heap[child])
			break;

		heap[parent] = heap[child];
	}

	heap[parent] = temp;
	return deleted;
}

Element peek()
{
	return heap[1];
}

void printHeap()
{
	for (int i = 1, j = 2; i <= n; i++)
	{
		if (i == j)
		{
			printf("\n");
			j += j;
		}
		printf("%2d ", heap[i]);
	}
	printf("\n\n");
}

void printList()
{
	for (int i = 0; i < capacity; i++)
	{
		printf("%2d ", list[i]);
	}
	printf("\n");
}
			
void release()
{
	free(heap);
	free(list);
}