#include <stdio.h>
#include <stdlib.h>
                            //implementation of DFS using adjacency List
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* CreateNode (int vertex) {
    struct Node* nn = (struct Node*) malloc (sizeof (struct Node));
    nn->vertex = vertex;
    nn->next = NULL;
    return nn;
}

struct Graph {
    int num_vertices;
    struct Node** Adj_list;
    int* Visited;
};

struct Graph* CreateGraph (int NoV) {
    struct Graph* graph = (struct Graph*) malloc (sizeof (struct Graph));
    graph->num_vertices = NoV;
    graph->Adj_list = (struct Node**) malloc (NoV * sizeof (struct Node*));
    graph->Visited = (int*) malloc (NoV * sizeof(int));    
    
    for (int i = 0; i < NoV; i++) {
        graph->Adj_list[i] = NULL;
        graph->Visited[i] = 0;
    }
    
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
    
    for (int i = 0; i < graph->num_vertices; i++) {
        printf ("Vertex %d: ", i);
        struct Node* temp = graph->Adj_list[i];
        while (temp != NULL) {
            printf ("%d ", temp->vertex);
            temp = temp->next;
        }
        printf ("\n");
    }
}

void DFS (struct Graph* graph, int vertex) {
    graph->Visited[vertex] = 1;
    printf ("Visited: %d\n", vertex);
    
    struct Node* temp = graph->Adj_list[vertex];
    while (temp != NULL) {
        int current_visit = temp->vertex;
        
        if (graph->Visited[current_visit] == 0)
            DFS (graph, current_visit);
        
        temp = temp->next;
    }
}

int main () {
    int NoV = 5;
    struct Graph* graph = CreateGraph (NoV);
    AddEdge (graph, 0, 1);
    AddEdge (graph, 0, 2);
    AddEdge (graph, 0, 3);
    AddEdge (graph, 1, 3);
    AddEdge (graph, 2, 3);
    AddEdge (graph, 2, 4);
    AddEdge (graph, 3, 4);
    PrintGraph (graph);
    DFS (graph, 0);
    return 0;
}