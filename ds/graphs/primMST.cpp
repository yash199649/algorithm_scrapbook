#include<bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int key[],bool mstSet[]){
    int m = 99999,m_i;
    for(int i=0;i<V;i++){
        if(!mstSet[i] && key[i]<m)
            m = key[i]; m_i = i;
    }
    return m_i;
}
 
void printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i] = 999999;
        mstSet[i]= false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count=0;count<V;count++){
        int u = minKey(key,mstSet);
        mstSet[u]=true;
        for(int v = 0;v<V;v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v]<key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(parent,V,graph);
}   

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    primMST(graph);
 
    return 0;
}