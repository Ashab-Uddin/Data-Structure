
/* implementation of adjacency list 
    (0)
    /   \
    /     \
  (1)     (3)
   |
   |
  (2)

  */

#include <stdio.h>
#include <stdlib.h>

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

struct Graph* CreateGraph (int NoV) {
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

int main () {
    int NoV = 4;
    struct Graph* graph = CreateGraph (NoV);
    AddEdge (graph, 0, 1);
    AddEdge (graph, 0, 3);
    AddEdge (graph, 1, 2);
    PrintGraph (graph);
    return 0;
}