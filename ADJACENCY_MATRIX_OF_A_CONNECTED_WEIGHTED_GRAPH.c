#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
void createAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) 
{
    int i, j;
    for (i = 0; i < vertices; i++) 
    {
        for (j = 0; j < vertices; j++) 
        {
            if (i == j) 
            {
                graph[i][j] = 0; 
            } 
            else 
            {
                graph[i][j] = INT_MAX; 
            }
        }
    }

    for (i = 0; i < vertices; i++) 
    {
        for (j = i + 1; j < vertices; j++) 
        {
            int weight;
            printf("Enter weight of edge between vertex %d and vertex %d: ", i, j);
            scanf("%d", &weight);
            graph[i][j] = graph[j][i] = weight;
        }
    }
}

void displayAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) 
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < vertices; i++) 
    {
        for (j = 0; j < vertices; j++)
        {
            if (graph[i][j] == INT_MAX) 
            {
                printf("0");
            }
            else 
            {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    createAdjacencyMatrix(graph, vertices);
    displayAdjacencyMatrix(graph, vertices);
    return 0;
}