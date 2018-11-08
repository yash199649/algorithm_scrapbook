#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int u,int v);
    bool isCyclic();
    bool isCycleUtil(int,vector<bool>,vector<bool>);
};

Graph::Graph(int V){
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph:: addEdge(int u,int v){
    adj[u].push_back(v);
}

bool Graph::isCycleUtil(int u, vector<bool> visited,vector<bool> s){
    if(visited[u]==false){
        visited[u]=true;
        s[u]=true;
        list<int>::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();++i){
            if(!visited[*i] && isCycleUtil(*i,visited,s))
                return true;
            else if(s[*i])
                return true;
        }
    }
    s[u]=false;
    return false;
   
}


bool Graph::isCyclic(){
    vector<bool> visited(V,false);
    vector<bool> s(V,false);
    for(int i=0;i<V;i++){
        if(isCycleUtil(i,visited,s))
            return true;
    }
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
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}