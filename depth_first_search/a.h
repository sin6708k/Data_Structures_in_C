// Depth First Search
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef int Vertex;
typedef struct Edge
{
	Vertex vertex;
	struct Edge* link;
} Edge;

int n;
Edge** graph;
bool* visited;

void init();

void searchOnGraph();
void searchOnEdges(const Edge* const);
void visit(const Vertex);

void addUndirectedEdge(const Vertex, const Vertex);
void addDirectedEdge(const Vertex, const Vertex);

void printGraph();
void printEdges(const Edge* const);

void releaseGraph();
void releaseEdges(Edge*);