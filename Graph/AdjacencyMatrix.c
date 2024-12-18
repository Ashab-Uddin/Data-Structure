#include<stdio.h>
#define NoV 5
void AddEdge(int Graph[][NoV], int i,int j){
    Graph[i][j] = 1;
    Graph[j][i] = 1;
}
void Display(int Graph[][NoV]){
    for(int i = 0;i<NoV;i++){
        for (int j = 0;j<NoV; j++){
            printf("%d ",Graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int Graph[NoV][NoV] = {0};
    AddEdge (Graph, 0, 1);
    AddEdge (Graph, 0, 2);
    AddEdge (Graph, 1, 2);
    AddEdge (Graph, 1, 3);
    AddEdge (Graph, 1, 4);
    AddEdge (Graph, 2, 4);
    AddEdge (Graph, 3, 4);
    Display(Graph);


}