#include <stdio.h>

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

void BFS (int Graph[][NoV], int start_vertex) {
    int Visited[NoV] = {0};
    int Queue[NoV];
    int front = 0, rear = 0;
    
    Visited[start_vertex] = 1;
    Queue[rear] = start_vertex;
    rear += 1;
    
    while (front < rear) {
        int current_vertex = Queue[front];
        front += 1;
        printf ("Visited: %d\n", current_vertex);
        
        for (int i = 0; i < NoV; i++) {
            if (Graph[current_vertex][i] == 1 && Visited[i] == 0) {
                Queue[rear] = i;
                rear += 1;
                Visited[i] = 1;
            }
        }
    }
}

int main () {
    int Graph[NoV][NoV] = {0};
    AddEdge (Graph, 0, 1);
    AddEdge (Graph, 0, 2);
    AddEdge (Graph, 1, 2);
    AddEdge (Graph, 1, 3);
    AddEdge (Graph, 1, 4);
    AddEdge (Graph, 2, 4);
    AddEdge (Graph, 3, 4);
    PrintGraph (Graph);
    BFS (Graph, 3);
    return 0;
}