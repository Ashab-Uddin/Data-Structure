#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int minDistance (int dist[], bool visit, int vertices) {
    int min = INF, min_index;
    for (int v = 0; v < vertices; v++) {
        if (visit[v] == false && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra (int Graph[][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES];
    bool visit[MAX_VERTICES];
    
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visit[i] = false;
    }
    
    dist[src] = 0;
    
    for (int v = 0; v < vertices; v++) {
        int u = minDistance (dist, visit, vertices);
        visit[u] = true;
        
        if (visit[v] == false && Graph[u][v] && dist[u] != INF && dist[u] + Graph[u][v] < dist[v]) 
            dist[v] = dist[u] + Graph[u][v];
    }
}