#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Structure to represent a graph
struct Graph
{
    int numVertices;
    struct Node **adjLists;
    int *visited;
};

// Function to create a node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph(int vertices)
{
    int i;
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth First Search algorithm
void DFS(struct Graph *graph, int vertex)
{
    struct Node *adjList = graph->adjLists[vertex];
    struct Node *temp = adjList;

    graph->visited[vertex] = 1; // Mark the current node as visited
    printf("%d ", vertex);      // Print the visited node

    // Recur for all the vertices adjacent to this vertex
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0)
        {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// Main function to demonstrate DFS with user input
int main()
{
    int i, vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest pairs):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Depth First Search starting from vertex 0:\n");
    DFS(graph, 0);

    // Free allocated memory (optional)
    for (i = 0; i < vertices; i++)
    {
        struct Node *temp = graph->adjLists[i];
        while (temp != NULL)
        {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
    getch();
    return 0;
}
