// Depth First Search
#include "a.h"

int main()
{
	init();

	printGraph();
	searchOnGraph();

	releaseGraph();
	return 0;
}

void init()
{
	FILE* file = fopen("input.txt", "r");
	fscanf(file, "%d", &n);
	
	graph = malloc(sizeof(*graph) * n);
	memset(graph, 0, sizeof(*graph) * n);
	visited = malloc(sizeof(*visited) * n);
	
	while (!feof(file))
	{
		Vertex u, v;
		fscanf(file, "%d %d", &u, &v);
		addUndirectedEdge(u, v);
	}
	fclose(file);
}

void searchOnGraph()
{
	while (true)
	{
		Vertex vertex;
		printf("vertex to start is ");
		scanf("%d", &vertex);

		if (vertex < 0 || vertex >= n)
			return;
		
		memset(visited, false, sizeof(*visited) * n);
		printf("search(%2d) -> ", vertex);
		visit(vertex);
		printf("\n\n");
	}
}

void searchOnEdges(const Edge* const edge)
{
	if (edge == NULL)
		return;
	
	visit(edge->vertex);
	searchOnEdges(edge->link);
}

void visit(const Vertex vertex)
{
	if (visited[vertex] == true)
		return;

	visited[vertex] = true;
	printf("%2d ", vertex);
	searchOnEdges(graph[vertex]);
}

void addUndirectedEdge(const Vertex u, const Vertex v)
{
	addDirectedEdge(u, v);
	addDirectedEdge(v, u);
}

void addDirectedEdge(const Vertex u, const Vertex v)
{
	Edge* edge = malloc(sizeof(*edge));
	edge->vertex = v;
	edge->link = graph[u];
	graph[u] = edge;
}

void printGraph()
{
	for (Vertex vertex = 0; vertex < n; vertex++)
	{
		printf("%2d : ", vertex);
		printEdges(graph[vertex]);
		printf("\n");
	}
	printf("\n");
}

void printEdges(const Edge* const edge)
{
	if (edge == NULL)
		return;

	printf("%2d ", edge->vertex);
	printEdges(edge->link);
}

void releaseGraph()
{
	for (Vertex vertex = 0; vertex < n; vertex++)
	{
		releaseEdges(graph[vertex]);
	}
	free(visited);
}

void releaseEdges(Edge* edge)
{
	if (edge == NULL)
		return;

	releaseEdges(edge->link);
	free(edge);
}