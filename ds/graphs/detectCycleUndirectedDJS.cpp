#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src,dest;
};

struct Graph{
    int V,E;
    struct edge *edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = 
           (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = 
        (struct edge*) malloc( graph->E * sizeof( struct edge ) );
 
    return graph;
}


int find(int parent[],int u){
    while(parent[u]!=-1)
        return find(parent,parent[u]);
    return u;
}

void Union(int arr[],int a,int b){
    if(find(arr,a)==find(arr,b))
        return;
    int ap = find(arr,a);
    int bp = find(arr,b);
    arr[ap]=bp;
}

bool isCycle(struct Graph *G){
    int *parent = (int*) malloc( G->V * sizeof(int) );
    for(int i=0;i<G->V;i++){
        parent[i]=-1;
    }
    for(int i=0;i<G->E;i++){
        if(find(parent,G->edge->src)==find(parent,G->edge->dest))
            return true;
        Union(parent,G->edge->src,G->edge->dest);
    }
    return false;
}


int main()
{
     
    int V = 3, E = 3;
    struct Graph* graph = createGraph(V, E);
 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
 
    return 0;
}