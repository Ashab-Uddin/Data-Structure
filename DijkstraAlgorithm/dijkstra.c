#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance
int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INF, min_index;

    for (int i = 0; i < vertices; i++) { // Corrected from v < vertices; v++
        if (sptSet[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the solution
void printSolution(int dist[], int vertices) {
    printf("Vertex\t\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) { // Corrected dist[il) to dist[i]
        printf("%d\t\t%d\n", i, dist[i]);
    }
    int v;
    printf("Enter the vertics you want to go: ");
    scanf("%d",&v);
    printf("Distance: %d m.",dist[v]);
}

// Dijkstra's algorithm function
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INF; // Corrected = to =
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = true;
 
        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, vertices);
}

int main() {
    int vertices = 9;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 5, vertices);
    return 0;
}