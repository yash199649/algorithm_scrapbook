#include<bits/stdc++.h>
using namespace std;

struct edges{
    int src,dest,weight;
};

struct Graph{
    int V,E;
    struct edges *edge;
};

Graph *createGraph(int v,int e){
    Graph *G = new Graph();
    G->V=v;
    G->E=e;
    G->edge = new edges[e];
    return G;
}

struct subset{
    int parent;
    int rank;
};

int find(struct subset subsets[],int u){
    if(subsets[u].parent==u)
        return u;
    return find(subsets,subsets[u].parent);
}

void Union(subset subsets[],int a,int b){
    int c = find(subsets,a);
    int d = find(subsets,b);
    if(c==d)
        return;
    if(subsets[c].rank>subsets[d].rank){
        subsets[d].parent = c;
    }
    else if(subsets[c].rank<subsets[d].rank){
        subsets[c].parent = d;
    }
    else{
        subsets[d].parent = c;
        subsets[c].rank++;
    }
}

int myComp(const void* a, const void* b)
{
    struct edges* a1 = (struct edges*)a;
    struct edges* b1 = (struct edges*)b;
    return a1->weight > b1->weight;
}
 
 void kruskal(Graph *g){
     int V = g->V;
     struct edges result[V];
     int e = 0;
     int i=0;
     qsort(g->edge,g->E,sizeof(g->edge[0]),myComp);
     struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while(e<V-1){
        struct edges next_edge = g->edge[i++];

        int x = find(subsets,next_edge.src);
        int y = find(subsets,next_edge.dest);
        if(x!=y){
            result[e++] = next_edge;
            Union(subsets,x,y);

        }
    }

     printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                 result[i].weight);
    return;
 }

 int main()
{
    int V = 4;  
    int E = 5;  
    struct Graph* graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
    kruskal(graph);
    cout<<endl;
 
    return 0;
}