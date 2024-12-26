#include <stdio.h>
                    //implementation of DFS using adjacency matrix
#define NoV 5

void AddEdge (int Graph[][NoV], int i, int j) {
    Graph[i][j] = 1;
    Graph[j][i] = 1;
}

void PrintGraph (int Graph[][NoV]) {
    for (int i = 0; i < NoV; i++) {
        for (int j = 0; j < NoV; j++) {
            printf ("%d ", Graph[i][j]);
        }
        printf ("\n");
    }
}

void DFS (int Graph[][NoV], int vertex, int Visited[]) {
    Visited [vertex] = 1;
    printf ("Visisted: %d\n", vertex);
    
    for (int i = 0; i < NoV; i++) {
        if (Graph[vertex][i] == 1 && Visited[i] == 0) 
            DFS (Graph, i, Visited);
    }
}

int main () {
    int Graph[NoV][NoV];
    int Visited[NoV] = {0};
    AddEdge (Graph, 0, 1);
    AddEdge (Graph, 0, 2);
    AddEdge (Graph, 0, 3);
    AddEdge (Graph, 1, 3);
    AddEdge (Graph, 2, 3);
    AddEdge (Graph, 2, 4);
    AddEdge (Graph, 3, 4);
    PrintGraph (Graph);
    DFS (Graph, 0, Visited);
    return 0;
}