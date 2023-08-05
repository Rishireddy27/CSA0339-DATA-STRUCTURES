#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to compare edges based on their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the parent of a node using path compression technique
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets using rank
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
    struct Edge result[MAX_VERTICES];
    int resultIndex = 0;
    int i = 0; // Index for sorted edges array
    int e = 0; // Index for result array

    // Sort the edges in non-decreasing order of their weights
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    // Allocate memory for subsets
    struct Subset subsets[numVertices];
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < numVertices - 1 && i < numEdges) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++) {
        printf("(%d - %d), Weight: %d\n", result[j].src, result[j].dest, result[j].weight);
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    struct Edge edges[numEdges];

    printf("Enter the source, destination, and weight for each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskalMST(edges, numVertices, numEdges);

    return 0;
}

