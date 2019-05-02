#include<bits/stdc++.h>
using namespace std;

enum Color{WHITE,GREY,BLACK};

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int);
    void addEdge(int,int);
    bool isCyclic();
};

Graph:: Graph(int V){
    this->V=V;
    this->adj = new list<int>[V];
}

void Graph:: addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
} 

bool isCycleUtil(list<int> *adj, int V, int u, int *color){
    color[u]=GREY;
    list<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();++it){
        if(color[*it]==GREY)
            return true;
        if(color[*it]==WHITE && isCycleUtil(adj,V,*it,color))
            return true;
    }

    color[u]=BLACK;
    return false;
}

bool Graph::isCyclic()
{
    int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;
    for (int i = 0; i < V; i++)
        if (color[i] == WHITE)
           if (isCycleUtil(adj,V,i, color) == true)
              return true;
 
    return false;
}
 
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
 
    return 0;
}