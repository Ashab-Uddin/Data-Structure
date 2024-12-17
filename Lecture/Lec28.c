#include <stdio.h>
#include <stdlib.h>

#define NoV 5

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* CreateNode (int vertex) {
    struct Node* nn = (struct Node*) malloc (sizeof(struct Node));
    nn->vertex = vertex;
    nn->next = NULL;
    return nn;
}

struct Graph {
    int number_vertices;
    struct Node** Adj_list;
};

struct Graph* CreateGraph () {
    struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph->number_vertices = NoV;
    graph->Adj_list = (struct Node**) malloc (NoV * sizeof (struct Node*));
    
    for (int i = 0; i < NoV; i++)
        graph->Adj_list[i] = NULL;
    
    return graph;
}

void AddEdge (struct Graph* graph, int i, int j) {
    struct Node* nn = CreateNode (j);
    nn->next = graph->Adj_list[i];
    graph->Adj_list[i] = nn;
    
    nn = CreateNode (i);
    nn->next = graph->Adj_list[j];
    graph->Adj_list[j] = nn;
}

void PrintGraph (struct Graph* graph) {
    if (graph == NULL) {
        printf ("Graph is empty\n");
        return;
    }
    
    for (int i = 0; i < graph->number_vertices; i++) {
        printf ("Vertex %d: ", i);
        struct Node* temp = graph->Adj_list[i];
        while (temp != NULL) {
            printf ("%d ", temp->vertex);
            temp = temp->next;
        }
        printf ("\n");
    }
}

void BFS (struct Graph* graph, int start_vertex) {
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
        
        struct Node* temp = graph->Adj_list[current_vertex];
        while (temp != NULL) {
            int vx = temp->vertex;
            if (Visited[vx] == 0) {
                Queue[rear] = vx;
                rear += 1;
                Visited[vx] = 1;
            }
            temp = temp->next;
        }
    }
}

int main () {
    struct Graph* graph = CreateGraph (NoV);
    AddEdge (graph, 0, 1);
    AddEdge (graph, 0, 2);
    AddEdge (graph, 1, 2);
    AddEdge (graph, 1, 3);
    AddEdge (graph, 1, 4);
    AddEdge (graph, 2, 4);
    AddEdge (graph, 3, 4);
    PrintGraph (graph);
    BFS (graph, 0);
    return 0;
}