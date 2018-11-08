#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int);
    void addEdge(int u,int v);
    bool isCycleUtil(int u,vector<bool> visited,int parent);
    bool isCycle();
};

Graph::Graph(int V){
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isCycleUtil(int u,vector<bool> visited, int parent){
    visited[u] = true;
    list<int>::iterator i;
    for(i = adj[u].begin();i!=adj[u].end();++i){
        if(!visited[*i] && isCycleUtil(*i,visited,u))
            return true;
        else if(*i != parent)
            return true;
    }
    return false;
}

bool Graph::isCycle(){
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i] && isCycleUtil(i,visited,-1))
            return true;
    }
    return false;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
 
    return 0;
}