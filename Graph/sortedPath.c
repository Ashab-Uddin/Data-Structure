#include <stdio.h>

void enqueue(int a);
int dequeue();
int q[20], r = 0, f = 0; // Global queue and pointers

int main()
{
    int node, edge, a, b, s, u, v, des, count = 0, S[20], x;
    int i, j;

    printf("Enter the number of nodes:\n");
    scanf("%d", &node);

    int matrix[node][node]; // Adjacency matrix
    int c[node];           // Visited state array
    int p[node];           // Parent array
    int d[node];           // Distance array

    // Initialize the adjacency matrix with 0
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
        {
            matrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges:\n");
    scanf("%d", &edge);

    printf("Enter the edges (node1 node2):\n");
    for (i = 0; i < edge; i++)
    {
        scanf("%d %d", &a, &b);
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    // Display the adjacency matrix
    printf("Adjacency matrix of the graph:\n");
    for (i = 0; i < node; i++)
    {
        for (j = 0; j < node; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // BFS Initialization
    printf("Enter the source node:\n");
    scanf("%d", &s);

    for (u = 0; u < node; u++)
    {
        c[u] = 1;  // White state: Unvisited
        p[u] = -1; // No parent
        d[u] = -1; // No distance calculated
    }

    c[s] = 2; // Gray state: Visiting
    d[s] = 0; // Distance of source is 0
    p[s] = -1;

    f = 0;
    r = 0; // Reset the queue pointers
    enqueue(s);

    // BFS Algorithm
    while (f != r)
    {
        u = dequeue();
        for (v = 0; v < node; v++)
        {
            if (matrix[u][v] == 1 && c[v] == 1)
            {
                c[v] = 2;         // Mark as gray
                d[v] = d[u] + 1;  // Update distance
                p[v] = u;         // Set parent
                enqueue(v);
            }
        }
        c[u] = 3; // Black state: Fully visited
    }

    // Path reconstruction
    printf("Enter the destination node:\n");
    scanf("%d", &des);

    x = des; // Start from the destination
    while (x != -1)
    {
        S[count++] = x; // Store path in reverse
        x = p[x];       // Move to the parent
    }

    printf("Shortest path from %d to %d is:\n", s, des);
    for (i = count - 1; i >= 0; i--)
    {
        printf("%d ", S[i]);
    }
    printf("\n");

    return 0;
}

// Enqueue function to add an element to the queue
void enqueue(int a)
{
    q[r++] = a;
}

// Dequeue function to remove an element from the queue
int dequeue()
{
    return q[f++];
}
