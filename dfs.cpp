#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Depth First Search (DFS) on a graph
void DFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int source, int visited[]) {
    visited[source] = 1;
    printf("%d ", source);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[source][i] == 1 && visited[i] == 0) {
            DFS(adjMatrix, numVertices, i, visited);
        }
    }
}

int main() {
    int numVertices, source;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the source vertex for DFS: ");
    scanf("%d", &source);

    int visited[MAX_VERTICES] = {0};

    printf("Depth First Traversal (starting from vertex %d): ", source);
    DFS(adjMatrix, numVertices, source, visited);
    printf("\n");

    return 0;
}

