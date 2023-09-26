#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct Node {
int vertex;
struct Node* next;
};
struct Graph {
int numNodes;
struct Node* adjacencyList[MAX_NODES];
};
void initGraph(struct Graph* graph, int numNodes) {
graph->numNodes = numNodes;
for (int i = 0; i < numNodes; i++) {
graph->adjacencyList[i] = NULL;
}
}
void addEdge(struct Graph* graph, int src, int dest) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->vertex = dest;
newNode->next = graph->adjacencyList[src];
graph->adjacencyList[src] = newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->vertex = src;
newNode->next = graph->adjacencyList[dest];
graph->adjacencyList[dest] = newNode;
}
void generateAdjacencyMatrix(struct Graph* graph, int
adjacencyMatrix[MAX_NODES][MAX_NODES]) {
for (int i = 0; i < graph->numNodes; i++) {
struct Node* currentNode = graph->adjacencyList[i];
while (currentNode != NULL) {
int vertex = currentNode->vertex;
adjacencyMatrix[i][vertex] = 1;
currentNode = currentNode->next;
}
}
}
void printAdjacencyMatrix(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes)
{
printf("Adjacency Matrix:\n");
for (int i = 0; i < numNodes; i++) {
for (int j = 0; j < numNodes; j++) {
printf("%d ", adjacencyMatrix[i][j]);
}
printf("\n");
}
}
int main() {
int numNodes = 5;
struct Graph graph;
initGraph(&graph, numNodes);
addEdge(&graph, 0, 1);
addEdge(&graph, 0, 2);
addEdge(&graph, 1, 3);
addEdge(&graph, 2, 3);
addEdge(&graph, 3, 4);
int adjacencyMatrix[MAX_NODES][MAX_NODES] = {0};
generateAdjacencyMatrix(&graph, adjacencyMatrix);
printAdjacencyMatrix(adjacencyMatrix, numNodes);
return 0;
}